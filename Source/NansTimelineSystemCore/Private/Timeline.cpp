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

#include "EventInterface.h"
#include "Event.h"

int32 FNTimeline::Counter = 0;

FNTimeline::FNTimeline()
{
	Label = FName(*FString::Format(TEXT("Timeline_{0}"), {Counter++}));
}

FNTimeline::FNTimeline(const FName& InLabel)
{
	Label = InLabel;
}

FNTimeline::~FNTimeline()
{
	SavedEvents.Empty();
	EventChanged.Clear();
}

void FNTimeline::Attached(const TArray<TSharedPtr<INEventInterface>>& EventsCollection)
{
	for (TSharedPtr<INEventInterface, ESPMode::Fast> Event : EventsCollection)
	{
		Attached(Event);
	}
}

bool FNTimeline::Attached(const TSharedPtr<INEventInterface>& Event)
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

			// Add object from Serialized data
			Events.Add(Event->GetUID(), Event);

			return true;
		}
	}

	EventChanged.Broadcast(Event, ENTimelineEvent::BeforeAttached, CurrentTime, -1);
	if (Event->IsAttachable())
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
		Event->SetAttachedTime(CurrentTime);
		if (Event->GetDelay() <= 0.f)
		{
			Event->Start(CurrentTime);
			Record.StartedAt = CurrentTime;
			EventChanged.Broadcast(Event, ENTimelineEvent::Start, CurrentTime, -1);
		}
		SavedEvents.Add(Record);
		Events.Add(Event->GetUID(), Event);
		EventChanged.Broadcast(Event, ENTimelineEvent::AfterAttached, CurrentTime, -1);
	}
	return Event->IsAttachable();
}

void FNTimeline::NotifyTick()
{
	CurrentTime += GetTickInterval();

	for (int32 Index = 0; Index < SavedEvents.Num(); ++Index)
	{
		FNEventSave& EventRecord = SavedEvents[Index];

		if (!Events.Contains(EventRecord.UID))
		{
			continue;
		}

		TSharedPtr<INEventInterface> Event = *Events.Find(EventRecord.UID);

		// This allow to manage manual expiration elsewhere
		if (Event->IsExpired() && Event->GetStartedAt() >= 0.f)
		{
			EventRecord.ExpiredTime = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
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
			EventChanged.Broadcast(Event, ENTimelineEvent::Start, CurrentTime, -1);
			continue;
		}

		Event->NotifyAddTime(GetTickInterval());
		EventRecord.LocalTime = Event->GetLocalTime();

		if (Event->IsExpired())
		{
			EventRecord.ExpiredTime = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
		}
	}
}

void FNTimeline::OnExpired(const TSharedPtr<INEventInterface>& Event, const float& ExpiredTime, const int32& Index)
{
	Event->SetExpiredTime(ExpiredTime);
	EventChanged.Broadcast(Event, ENTimelineEvent::Expired, ExpiredTime, Index);
	Events.FindAndRemoveChecked(Event->GetUID());
}

float FNTimeline::GetTickInterval() const
{
	return TickInterval;
}

void FNTimeline::SetTickInterval(const float& InTickInterval)
{
	TickInterval = InTickInterval;
}

void FNTimeline::SetCurrentTime(const float& InCurrentTime)
{
	CurrentTime = InCurrentTime;
}

float FNTimeline::GetCurrentTime() const
{
	return CurrentTime;
}

void FNTimeline::SetLabel(const FName& InLabel)
{
	Label = InLabel;
}

FName FNTimeline::GetLabel() const
{
	return Label;
}

void FNTimeline::Clear()
{
	SavedEvents.Empty();
	Events.Empty();
	CurrentTime = 0;
}

TSharedPtr<INEventInterface> FNTimeline::GetEvent(const FString& InUID) const
{
	TSharedPtr<INEventInterface> Event;
	if (Events.Contains(InUID))
	{
		Event = *Events.Find(InUID);
	}
	else
	{
		for (const auto& SavedEvent : SavedEvents)
		{
			if (SavedEvent.UID == InUID)
			{
				Event = MakeShareable(new FNEvent(SavedEvent));
				break;
			}
		}
	}
	return Event;
}

TArray<TSharedPtr<INEventInterface>> FNTimeline::GetEvents() const
{
	TArray<TSharedPtr<INEventInterface>> ReturnedEvents;
	Events.GenerateValueArray(ReturnedEvents);
	return ReturnedEvents;
}

void FNTimeline::Archive(FArchive& Ar)
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
			TSharedPtr<INEventInterface> Event = MakeShareable(new FNEvent(EventSaved));
			Attached(Event);
		}
	}
}
