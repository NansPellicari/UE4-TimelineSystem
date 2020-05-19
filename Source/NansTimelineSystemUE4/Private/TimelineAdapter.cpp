#include "TimelineAdapter.h"

#include "Manager/TimelineManagerBaseAdapter.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineManagerBase.h"

void FNEventRecord::Serialize(FArchive& Ar, UNTimelineAdapter* Timeline)
{
	if (Ar.IsSaving() && Event != nullptr)
	{
		Event->Serialize(Ar);
	}
	if (Ar.IsLoading() && EventClassName != FString(""))
	{
		UClass* Class = FindObject<UClass>(ANY_PACKAGE, *EventClassName);
		Event = Timeline->CreateNewEvent(Class, Label);
		Event->Serialize(Ar);
	}
}

void UNTimelineAdapter::Init(UNTimelineManagerBaseAdapter* TimelineManager, FName _Label)
{
	Timeline = MakeShareable(new NTimeline(static_cast<NTimelineManagerBase*>(TimelineManager), _Label));
	Timeline->EventExpired.BindUObject(this, &UNTimelineAdapter::OnEventExpired);
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

bool UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)
{
	check(Timeline.IsValid());
	bool bIsAttached = Timeline->Attached(Event->GetEvent());
	if (bIsAttached)
	{
		FNEventRecord Record;
		Record.Event = Event;
		int32 Last = Timeline->GetEvents().Num() - 1;
		Last = Last > 0 ? Last : 0;
		EventStore.Insert(Record, Last);
		// refresh data from the last Timeline->GetEvents() entry
		RefreshRecordData(Last);
	}
	return bIsAttached;
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

void UNTimelineAdapter::RefreshRecordData(const int32& Index)
{
	const FEventTuple& Tuple = Timeline->GetEvents()[Index];
	FNEventRecord& Record = EventStore[Index];

	if (Index > 0 && Record.Event->GetEvent() != Tuple.Get<0>())
	{
		UE_LOG(LogTemp,
			Error,
			TEXT("%s and its adapter are not synchronized (for Index %d),"
				 "I prefer stopping here rather making dirty things."
				 "Please check your EventStore population."),
			*Timeline->GetLabel().ToString(),
			Index);
		return;
	}

	Record.AttachedTime = Tuple.Get<1>();
	Record.Delay = Tuple.Get<2>();
	Record.Duration = Tuple.Get<3>();
	Record.Label = Tuple.Get<4>();
	Record.ExpiredTime = Tuple.Get<5>();
}

void UNTimelineAdapter::OnEventExpired(TSharedPtr<NTimelineEventBase> Event, const float& ExpiredTime, const int32& Index)
{
	RefreshRecordData(Index);
	FNEventRecord& Record = EventStore[Index];
	Record.Event = nullptr;
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
		for (int32 i = 0; i < Timeline->GetEvents().Num(); i++)
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
