#include "TimelineAdapter.h"

#include "Manager/TimelineManagerBaseAdapter.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineManagerAbstract.h"

void FNEventRecord::Serialize(FArchive& Ar, UNTimelineAdapter* Timeline)
{
	if (Ar.IsSaving() && Event != nullptr)
	{
		Event->Serialize(Ar);
	}
	if (Ar.IsLoading() && EventClass != nullptr)
	{
		Event = Timeline->CreateNewEvent(EventClass, Label);
		Event->Serialize(Ar);
	}
}

void UNTimelineAdapter::Init(UNTimelineManagerBaseAdapter* TimelineManager, FName _Label)
{
	Timeline = MakeShareable(new NTimeline(static_cast<NTimelineManagerAbstract*>(TimelineManager), _Label));
}

void UNTimelineAdapter::Clear()
{
	EventStore.Empty();
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}

void UNTimelineAdapter::SetCurrentTime(float _CurrentTime)
{
	NTimeline::SetCurrentTime(_CurrentTime);
	if (!Timeline.IsValid()) return;
	Timeline->SetCurrentTime(_CurrentTime);
}

void UNTimelineAdapter::SetLabel(FName _Label)
{
	NTimeline::SetLabel(_Label);
	if (!Timeline.IsValid()) return;
	Timeline->SetLabel(_Label);
}

TSharedPtr<NTimeline> UNTimelineAdapter::GetTimeline() const
{
	return Timeline;
}

void UNTimelineAdapter::NotifyTick()
{
	if (!Timeline.IsValid()) return;

	Timeline->NotifyTick();
}

void UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)
{
	check(Timeline.IsValid());
	FNEventRecord Record;
	Record.Event = Event;
	Timeline->Attached(Event->GetEvent());
	const FEventTuple& Tuple = Timeline->GetEvents().Last();

	Record.AttachedTime = Tuple.Get<1>();
	Record.Delay = Tuple.Get<2>();
	Record.Duration = Tuple.Get<3>();
	Record.Label = Tuple.Get<4>();
	Record.ExpiredTime = Tuple.Get<5>();

	EventStore.Add(Record);
}

const TArray<FNEventRecord> UNTimelineAdapter::GetAdaptedEvents() const
{
	return EventStore;
}

NTimeline::FEventTuple UNTimelineAdapter::ConvertRecordToTuple(FNEventRecord const Record)
{
	TSharedPtr<NTimelineEventBase> Event;
	if (Record.Event != nullptr)
	{
		Event = Record.Event->GetEvent();
	}
	return NTimeline::FEventTuple(Event, Record.AttachedTime, Record.Delay, Record.Duration, Record.Label, Record.ExpiredTime);
}

float UNTimelineAdapter::GetCurrentTime()
{
	check(Timeline.IsValid());
	return Timeline->GetCurrentTime();
}

FName UNTimelineAdapter::GetLabel() const
{
	check(Timeline.IsValid());
	return Timeline->GetLabel();
}

UNTimelineEventAdapter* UNTimelineAdapter::CreateNewEvent(
	TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration, float Delay)
{
	UNTimelineEventAdapter* Object = UNTimelineEventAdapter::CreateObject<UNTimelineEventAdapter>(this, Class, Name);
	if (Duration > 0)
	{
		Object->SetDuration(Duration);
	}
	if (Delay > 0)
	{
		Object->SetDelay(Delay);
	}

	return Object;
}

void UNTimelineAdapter::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (Ar.IsSaving())
	{
		CurrentTime = Timeline->GetCurrentTime();
		Label = Timeline->GetLabel();
		for (int i = 0; i < Timeline->GetEvents().Num(); i++)
		{
			const NTimeline::FEventTuple& Tuple = Timeline->GetEvents()[i];
			FNEventRecord& Record = EventStore[i];

			Record.AttachedTime = Tuple.Get<1>();
			Record.Delay = Tuple.Get<2>();
			Record.Duration = Tuple.Get<3>();
			Record.Label = Tuple.Get<4>();
			Record.ExpiredTime = Tuple.Get<5>();
		}
	}
	if (Ar.IsLoading())
	{
		EventStore.Empty();
	}

	Ar << Label;
	Ar << CurrentTime;
	Ar << EventStore;

	if (Ar.IsLoading())
	{
		Timeline->Clear();
		Timeline->SetLabel(Label);
		Timeline->SetCurrentTime(CurrentTime);
	}

	if (EventStore.Num() > 0)
	{
		for (FNEventRecord& Record : EventStore)
		{
			Record.Serialize(Ar, this);
			if (Ar.IsLoading())
			{
				Timeline->SetTuple(UNTimelineAdapter::ConvertRecordToTuple(Record));
			}
		}
	}
}

void UNTimelineAdapter::BeginDestroy()
{
	Super::BeginDestroy();
	Clear();
}
