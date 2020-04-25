#include "Timeline.h"

#include "TimelineEventBase.h"
#include "TimelineManagerAbstract.h"

NTimeline::NTimeline(NTimelineManagerAbstract* TimelineTimer)
{
	TimelineTimer->SetTimeline(this);
	TimelineTimer->SetTickInterval(GetTickInterval());
	TimerManager = MakeShareable(TimelineTimer);
}

NTimeline::~NTimeline()
{
	Reset();
	TimerManager.Reset();
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

void NTimeline::Reset()
{
	Events.Empty();
	CurrentTime = 0;
}
