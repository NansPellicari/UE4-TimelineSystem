// Copyright Nans Pellicari, 2021

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
	ExpiredEvents.Empty();
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

void FNTimeline::NotifyTick(const float& InDeltaTime)
{
	CurrentTime += InDeltaTime;

	// TODO remove this index not useful anymore
	int32 Index = 0;
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

		Event->AddTime(InDeltaTime);
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
		ExpiredEvents.Add(EventToRemoved);
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
	ExpiredEvents.Empty();
	CurrentTime = 0;
}

TSharedPtr<INEvent> FNTimeline::GetEvent(const FString& InUID) const
{
	const TSharedPtr<INEvent>* EventPtr = Events.FindByKey(InUID);
	if (EventPtr == nullptr) return nullptr;
	TSharedPtr<INEvent> Event = *EventPtr;
	return Event;
}

TSharedPtr<INEvent> FNTimeline::GetExpiredEvent(const FString& InUID) const
{
	const TSharedPtr<INEvent>* EventPtr = ExpiredEvents.FindByKey(InUID);
	if (EventPtr == nullptr) return nullptr;
	TSharedPtr<INEvent> Event = *EventPtr;
	return Event;
}

TArray<TSharedPtr<INEvent>> FNTimeline::GetEvents() const
{
	return Events;
}

TArray<TSharedPtr<INEvent>> FNTimeline::GetExpiredEvents() const
{
	return ExpiredEvents;
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
	int32 NumExpiredEvents = ExpiredEvents.Num();

	Ar << NumEvents;
	Ar << NumExpiredEvents;

	if (Ar.IsLoading())
	{
		Events.Reserve(NumEvents);
		for (int32 Idx = 0; Idx < NumEvents; Idx++)
		{
			Events.Add(MakeShared<FNEvent>());
		}

		ExpiredEvents.Reserve(NumExpiredEvents);
		for (int32 Idx = 0; Idx < NumExpiredEvents; Idx++)
		{
			ExpiredEvents.Add(MakeShared<FNEvent>());
		}
	}

	for (int32 Idx = 0; Idx < NumEvents; Idx++)
	{
		TSharedPtr<INEvent> Event = Events[Idx];
		Event->Archive(Ar);
	}

	for (int32 Idx = 0; Idx < NumExpiredEvents; Idx++)
	{
		TSharedPtr<INEvent> Event = ExpiredEvents[Idx];
		Event->Archive(Ar);
	}
}
