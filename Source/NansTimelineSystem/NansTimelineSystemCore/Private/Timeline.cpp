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

#include "TimelineEventBase.h"
#include "TimelineManagerAbstract.h"

NTimeline::NTimeline(NTimelineManagerAbstract* TimelineTimer)
{
	static int32 Counter;
	TimelineTimer->SetTimeline(this);
	TimelineTimer->SetTickInterval(GetTickInterval());
	Label = FName(*FString::Format(TEXT("Timeline_{0}"), {Counter++}));
}

NTimeline::~NTimeline()
{
	Clear();
}

const TArray<NTimeline::FEventTuple> NTimeline::GetEvents() const
{
	return Events;
}

void NTimeline::Attached(TArray<TSharedPtr<NTimelineEventBase>> EventsCollection)
{
	for (auto Event : EventsCollection)
	{
		Attached(Event);
	}
}

void NTimeline::Attached(TSharedPtr<NTimelineEventBase> Event)
{
	if (Event->GetDelay() <= 0.f)
	{
		Event->Start(CurrentTime);
	}

	bool bCanAttached = BeforeOnAttached(Event, CurrentTime);
	if (bCanAttached)
	{
		Events.Add(FEventTuple(Event, CurrentTime, Event->GetDelay(), Event->GetDuration(), Event->GetEventLabel(), 0.f));
		AfterOnAttached(Event, CurrentTime);
	}
}

void NTimeline::NotifyTick()
{
	CurrentTime += GetTickInterval();

	for (FEventTuple& EventTuple : Events)
	{
		TSharedPtr<NTimelineEventBase> Event = EventTuple.Get<0>();

		if (!Event.IsValid())
		{
			continue;
		}

		// This allow to manage expiration elsewhere
		if (Event->IsExpired())
		{
			OnExpired(Event, CurrentTime);
			EventTuple.Get<5>() = CurrentTime;
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
			OnExpired(Event, CurrentTime);
			EventTuple.Get<5>() = CurrentTime;
			Event.Reset();
			EventTuple.Get<0>().Reset();
		}
	}
}

float NTimeline::GetCurrentTime()
{
	return CurrentTime;
}

void NTimeline::Clear()
{
	Events.Empty();
	CurrentTime = 0;
}

void NTimeline::SetLabel(FName _Label)
{
	Label = _Label;
}
