// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Timeline.h"

#include "TimelineManager.h"

#include <iostream>

#include "Event.h"

NTimeline::NTimeline(NTimelineManager* TimelineTimer, FName _Label)
{
	static int32 Counter;
	TimelineTimer->SetTickInterval(GetTickInterval());
	Label = _Label;
	if (_Label == NAME_None)
	{
		Label = FName(*FString::Format(TEXT("Timeline_{0}"), {Counter++}));
	}
}

NTimeline::~NTimeline()
{
	SavedEvents.Empty();
	EventExpired.Clear();
}

void NTimeline::Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection)
{
	for (auto Event : EventsCollection)
	{
		Attached(Event);
	}
}

bool NTimeline::Attached(TSharedPtr<NEventInterface> Event)
{
	for (int32 Index = 0; Index < SavedEvents.Num(); ++Index)
	{
		FNEventSave& EventRecord = SavedEvents[Index];
		// manage unique event or event from Serialized data
		if (EventRecord.UID == Event->GetUID())
		{
			// Only add unique event
			if (Events.Contains(EventRecord.UID))
			{
				return false;
			}
			else
			{
				// Add object from Serialized data
				Events.Add(Event->GetUID(), Event);

				return true;
			}
		}
	}


	bool bCanAttached = BeforeOnAttached(Event, CurrentTime);
	if (bCanAttached)
	{
		FNEventSave Record =
			FNEventSave(
				Event->GetUID(),
				CurrentTime,
				Event->GetDelay(),
				Event->GetDuration(),
				Event->GetEventLabel(),
				0.f
			);
		if (Event->GetDelay() <= 0.f)
		{
			Event->Start(CurrentTime);
			Record.StartedAt = CurrentTime;
		}
		SavedEvents.Add(Record);
		Events.Add(Event->GetUID(), Event);
		AfterOnAttached(Event, CurrentTime);
	}
	return bCanAttached;
}

void NTimeline::NotifyTick()
{
	CurrentTime += GetTickInterval();

	for (int32 Index = 0; Index < SavedEvents.Num(); ++Index)
	{
		FNEventSave& EventRecord = SavedEvents[Index];

		if (!Events.Contains(EventRecord.UID))
		{
			continue;
		}

		TSharedPtr<NEventInterface> Event = *Events.Find(EventRecord.UID);

		// This allow to manage manual expiration elsewhere
		if (Event->IsExpired() && Event->GetStartedAt() >= 0.f)
		{
			EventRecord.ExpiredTime = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
			Events.FindAndRemoveChecked(EventRecord.UID);
			continue;
		}

		const float AttachedAt = EventRecord.AttachedTime;
		const float IntervalAttachedAt = CurrentTime - AttachedAt;

		if (Event->GetDelay() > 0 && Event->GetDelay() > IntervalAttachedAt)
		{
			continue;
		}

		if (Event->GetStartedAt() < 0.f)
		{
			Event->Start(CurrentTime);
			EventRecord.StartedAt = CurrentTime;
			continue;
		}

		Event->NotifyAddTime(GetTickInterval());
		EventRecord.LocalTime = Event->GetLocalTime();

		if (Event->IsExpired())
		{
			EventRecord.ExpiredTime = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
			// TODO refacto: should be great to have this here
			// Event->PreDelete();
			Events.FindAndRemoveChecked(EventRecord.UID);
		}
	}
}

void NTimeline::OnExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index)
{
	EventExpired.Broadcast(Event, ExpiredTime, Index);
}

FNTimelineEventDelegate& NTimeline::OnEventExpired()
{
	return EventExpired;
}

const float NTimeline::GetTickInterval() const
{
	return TickInterval;
}

void NTimeline::SetTickInterval(float _TickInterval)
{
	TickInterval = _TickInterval;
}

void NTimeline::SetCurrentTime(float _CurrentTime)
{
	CurrentTime = _CurrentTime;
}

float NTimeline::GetCurrentTime() const
{
	return CurrentTime;
}

void NTimeline::SetLabel(FName _Label)
{
	Label = _Label;
}

FName NTimeline::GetLabel() const
{
	return Label;
}

void NTimeline::Clear()
{
	SavedEvents.Empty();
	Events.Empty();
	CurrentTime = 0;
}

TSharedPtr<NEventInterface> NTimeline::GetEvent(FString _UID)
{
	TSharedPtr<NEventInterface> Event;
	if (Events.Contains(_UID))
	{
		Event = *Events.Find(_UID);
	}
	else
	{
		for (const auto& SavedEvent : SavedEvents)
		{
			if (SavedEvent.UID == _UID)
			{
				Event = MakeShareable(new NEvent(SavedEvent));
				break;
			}
		}
	}
	return Event;
}

TArray<TSharedPtr<NEventInterface>> NTimeline::GetEvents()
{
	TArray<TSharedPtr<NEventInterface>> ReturnedEvents;
	Events.GenerateValueArray(ReturnedEvents);
	return ReturnedEvents;
}


void NTimeline::PreDelete()
{
	Clear();
}

void NTimeline::Archive(FArchive& Ar)
{
	if (Ar.IsLoading())
	{
		Clear();
	}

	Ar << Label;
	Ar << CurrentTime;
	Ar << TickInterval;
	Ar << SavedEvents;

	if (Ar.IsLoading())
	{
		for (const FNEventSave& EventSaved : SavedEvents)
		{
			TSharedPtr<NEventInterface> Event = MakeShareable(new NEvent(EventSaved));
			Attached(Event);
		}
	}
}
