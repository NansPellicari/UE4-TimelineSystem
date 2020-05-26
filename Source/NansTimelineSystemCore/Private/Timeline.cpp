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

#include "TimelineManagerBase.h"

NTimeline::NTimeline(NTimelineManagerBase* TimelineTimer, FName _Label)
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
	Clear();
}

void NTimeline::Attached(TArray<TSharedPtr<NTimelineEventBase>> EventsCollection)
{
	for (auto Event : EventsCollection)
	{
		Attached(Event);
	}
}

bool NTimeline::Attached(TSharedPtr<NTimelineEventBase> Event)
{
	if (Event->GetDelay() <= 0.f)
	{
		Event->Start(CurrentTime);
	}

	bool bCanAttached = BeforeOnAttached(Event, CurrentTime);
	if (bCanAttached)
	{
		SetTuple(FEventTuple(Event, CurrentTime, Event->GetDelay(), Event->GetDuration(), Event->GetEventLabel(), 0.f));
		AfterOnAttached(Event, CurrentTime);
	}
	return bCanAttached;
}

void NTimeline::NotifyTick()
{
	CurrentTime += GetTickInterval();

	int32 Index = 0;
	for (Index; Index < Events.Num(); ++Index)
	{
		FEventTuple& EventTuple = Events[Index];
		TSharedPtr<NTimelineEventBase> Event = EventTuple.Get<0>();

		if (!Event.IsValid())
		{
			continue;
		}

		// This allow to manage expiration elsewhere
		if (Event->IsExpired())
		{
			EventTuple.Get<5>() = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
			Event.Reset();
			EventTuple.Get<0>().Reset();
			continue;
		}

		float AttachedAt = EventTuple.Get<1>();
		float IntervalAttachedAt = CurrentTime - AttachedAt;

		if (Event->GetDelay() > 0 && Event->GetDelay() >= IntervalAttachedAt)
		{
			continue;
		}

		if (Event->GetStartedAt() < 0.f)
		{
			Event->Start(CurrentTime);
		}

		// TODO should be an idea to have a possiblity to add a time relative to the timeline...
		// float IntervalFromLastNotification = CurrentTime - Event->GetLocalTime();
		Event->NotifyAddTime(GetTickInterval());

		if (Event->IsExpired())
		{
			EventTuple.Get<5>() = CurrentTime;
			OnExpired(Event, CurrentTime, Index);
			Event.Reset();
			EventTuple.Get<0>().Reset();
		}
	}
}

void NTimeline::OnExpired(TSharedPtr<NTimelineEventBase> Event, const float& ExpiredTime, const int32& Index)
{
	EventExpired.ExecuteIfBound(Event, ExpiredTime, Index);
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

void NTimeline::SetTuple(NTimeline::FEventTuple Tuple)
{
	Events.Add(Tuple);
}

void NTimeline::Clear()
{
	Events.Empty();
	CurrentTime = 0;
}

const TArray<NTimeline::FEventTuple> NTimeline::GetEvents() const
{
	return Events;
}