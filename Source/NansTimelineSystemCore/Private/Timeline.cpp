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
	Events.Empty();
	EventChanged.Clear();
}

void FNTimeline::Attached(const TArray<TSharedPtr<INEvent>>& EventsCollection)
{
	for (TSharedPtr<INEvent, ESPMode::Fast> Event : EventsCollection)
	{
		Attached(Event);
	}
}

bool FNTimeline::Attached(const TSharedPtr<INEvent>& Event)
{
	EventChanged.Broadcast(Event, ENTimelineEvent::BeforeAttached, CurrentTime, -1);
	if (Event->IsAttachable())
	{
		Event->SetAttachedTime(CurrentTime);

		Events.Add(Event);
		// TODO remove this unuseful index
		const int32 NewIndex = Events.Num() + 1;

		if (Event->GetDelay() <= 0.f)
		{
			StartEvent(Event, NewIndex);
		}

		EventChanged.Broadcast(Event, ENTimelineEvent::AfterAttached, CurrentTime, NewIndex);
	}
	return Event->IsAttachable();
}

void FNTimeline::StartEvent(const TSharedPtr<INEvent>& Event, const int32& Index) const
{
	Event->Start(CurrentTime);
	EventChanged.Broadcast(Event, ENTimelineEvent::Start, CurrentTime, Index);
}

void FNTimeline::NotifyTick()
{
	CurrentTime += GetTickInterval();

	// TODO remove this index not useful anymore
	int32 Index = 0;
	// TODO Create an list of expired events to save
	TArray<TSharedPtr<INEvent>> EventsToRemoved;
	for (const TSharedPtr<INEvent>& Event : Events)
	{
		Index++;

		// This allow to manage manual expiration elsewhere using the INEvent::Stop() function
		if (Event->IsExpired() && Event->GetStartedAt() >= 0.f)
		{
			OnExpired(Event, CurrentTime, Index);
			EventsToRemoved.Add(Event);
			continue;
		}

		const float AttachedAt = Event->GetAttachedTime();
		const float IntervalAttachedAt = CurrentTime - AttachedAt;

		if (Event->GetDelay() > 0 && Event->GetDelay() > IntervalAttachedAt)
		{
			continue;
		}

		if (Event->GetStartedAt() < 0.f)
		{
			StartEvent(Event, Index);
			continue;
		}

		Event->AddTime(GetTickInterval());
		EventChanged.Broadcast(Event, ENTimelineEvent::Tick, CurrentTime, Index);

		if (Event->IsExpired())
		{
			Event->Stop();
			OnExpired(Event, CurrentTime, Index);
			EventsToRemoved.Add(Event);
		}
	}

	for (TSharedPtr<INEvent> EventToRemoved : EventsToRemoved)
	{
		Events.Remove(EventToRemoved);
	}
	EventsToRemoved.Empty();
}

void FNTimeline::OnExpired(const TSharedPtr<INEvent>& Event, const float& ExpiredTime, const int32& Index) const
{
	Event->SetExpiredTime(ExpiredTime);
	EventChanged.Broadcast(Event, ENTimelineEvent::Expired, ExpiredTime, Index);
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
	Events.Empty();
	CurrentTime = 0;
}

TSharedPtr<INEvent> FNTimeline::GetEvent(const FString& InUID) const
{
	TSharedPtr<INEvent> Event = *Events.FindByKey(InUID);
	return Event;
}

TArray<TSharedPtr<INEvent>> FNTimeline::GetEvents() const
{
	return Events;
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

	int32 NumEvents = Events.Num();
	Ar << NumEvents;

	if (Ar.IsLoading())
	{
		Events.Reserve(NumEvents);
		for (int32 Idx = 0; Idx < NumEvents; Idx++)
		{
			Events.Add(MakeShared<FNEvent>());
		}
	}

	for (int32 Idx = 0; Idx < NumEvents; Idx++)
	{
		TSharedPtr<INEvent> Event = Events[Idx];
		Event->Archive(Ar);
	}
}
