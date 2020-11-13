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
	Events.Empty();
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
	for (int32 Index = 0; Index < Events.Num(); ++Index)
	{
		FNEventSave& EventRecord = Events[Index];
		// manage unique event or event from Serialized data
		if (EventRecord.UID == Event->GetUID())
		{
			// Only add unique event
			if (EventsObjects.Contains(EventRecord.UID))
			{
				return false;
			}
			else
			{
				// Add object from Serialized data
				EventsObjects.Add(Event->GetUID(), Event);
				return true;
			}
		}
	}

	bool bCanAttached = true;

	bCanAttached = BeforeOnAttached(Event, CurrentTime);
	if (bCanAttached)
	{
		FNEventSave Record =
			FNEventSave(Event->GetUID(), CurrentTime, Event->GetDelay(), Event->GetDuration(), Event->GetEventLabel(), 0.f);
		if (Event->GetDelay() <= 0.f)
		{
			Event->Start(CurrentTime);
			Record.StartedAt = CurrentTime;
		}
		Events.Add(Record);
		EventsObjects.Add(Event->GetUID(), Event);
		AfterOnAttached(Event, CurrentTime);
	}
	return bCanAttached;
}

void NTimeline::NotifyTick()
{
	CurrentTime += GetTickInterval();

	for (int32 Index = 0; Index < Events.Num(); ++Index)
	{
		FNEventSave& EventRecord = Events[Index];

		if (!EventsObjects.Contains(EventRecord.UID))
		{
			continue;
		}

		TSharedPtr<NEventInterface> Event = *EventsObjects.Find(EventRecord.UID);

		// This allow to manage manual expiration elsewhere
		if (Event->IsExpired() && Event->GetStartedAt() >= 0.f)
		{
			EventRecord.ExpiredTime = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
			EventsObjects.FindAndRemoveChecked(EventRecord.UID);
			continue;
		}

		float AttachedAt = EventRecord.AttachedTime;
		float IntervalAttachedAt = CurrentTime - AttachedAt;

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
			EventsObjects.FindAndRemoveChecked(EventRecord.UID);
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
	Events.Empty();
	CurrentTime = 0;
}

const TArray<FNEventSave> NTimeline::GetEvents() const
{
	return Events;
}

TMap<FString, TSharedPtr<NEventInterface>> NTimeline::GetEventObjects()
{
	return EventsObjects;
}

TSharedPtr<NEventInterface> NTimeline::GetEvent(FString _UID)
{
	TSharedPtr<NEventInterface> Event;
	if (EventsObjects.Contains(_UID))
	{
		Event = *EventsObjects.Find(_UID);
	}
	return Event;
}

void NTimeline::PreDelete()
{
	Clear();
}
void NTimeline::Archive(FArchive& Ar)
{
	if (Ar.IsSaving())
	{
		EventsCount = Events.Num();
	}
	Ar << Label;
	Ar << CurrentTime;
	Ar << TickInterval;
	Ar << Events;

	if (Ar.IsLoading())
	{
		// clean up to allow decorator to fill with real objects
		EventsObjects.Empty();
	}
}
