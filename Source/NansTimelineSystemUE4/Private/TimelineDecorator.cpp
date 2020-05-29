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

#include "TimelineDecorator.h"

#include "Manager/TimelineManagerDecorator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineManager.h"

void FNEventRecord::Serialize(FArchive& Ar, UNTimelineDecorator* Timeline)
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

void UNTimelineDecorator::Init(UNTimelineManagerDecorator* TimelineManager, FName _Label)
{
	// TODO remove static cast, not useful anymore??
	Timeline = MakeShareable(new NTimeline(static_cast<NTimelineManager*>(TimelineManager), _Label));
	Timeline->EventExpired.BindUObject(this, &UNTimelineDecorator::OnEventExpired);
}

void UNTimelineDecorator::SetTickInterval(float _TickInterval)
{
	if (!Timeline.IsValid()) return;
	TickInterval = _TickInterval;
	Timeline->SetTickInterval(TickInterval);
}

void UNTimelineDecorator::SetCurrentTime(float _CurrentTime)
{
	CurrentTime = _CurrentTime;
	if (!Timeline.IsValid()) return;
	Timeline->SetCurrentTime(_CurrentTime);
}

void UNTimelineDecorator::SetLabel(FName _Label)
{
	Label = _Label;
	if (!Timeline.IsValid()) return;
	Timeline->SetLabel(_Label);
}

TSharedPtr<NTimelineInterface> UNTimelineDecorator::GetTimeline() const
{
	return Timeline;
}

void UNTimelineDecorator::NotifyTick()
{
	if (!Timeline.IsValid()) return;

	Timeline->NotifyTick();
}

void UNTimelineDecorator::AddEvent(UNTimelineEventDecorator* Event)
{
	check(Timeline.IsValid());
	FNEventRecord Record;
	Record.Event = Event;
	int32 Last = Timeline->GetEvents().Num() - 1;
	Last = Last > 0 ? Last : 0;
	EventStore.Insert(Record, Last);
	// refresh data from the last Timeline->GetEvents() entry
	RefreshRecordData(Last);
}

const TArray<FNEventRecord> UNTimelineDecorator::GetAdaptedEvents() const
{
	return EventStore;
}

NTimeline::FEventTuple UNTimelineDecorator::ConvertRecordToTuple(FNEventRecord const Record)
{
	TSharedPtr<NTimelineEventInterface> Event;
	if (Record.Event != nullptr)
	{
		Event = Record.Event->GetEvent();
	}
	return NTimeline::FEventTuple(Event, Record.AttachedTime, Record.Delay, Record.Duration, Record.Label, Record.ExpiredTime);
}

void UNTimelineDecorator::RefreshRecordData(const int32& Index)
{
	const NTimeline::FEventTuple& Tuple = Timeline->GetEvents()[Index];
	FNEventRecord& Record = EventStore[Index];

	if (Index > 0 && Record.Event->GetUID() != Tuple.Get<0>()->GetUID())
	{
		UE_LOG(LogTemp,
			Error,
			TEXT("%s and its decorator are not synchronized (for Index %d),"
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

void UNTimelineDecorator::OnEventExpired(TSharedPtr<NTimelineEventInterface> Event, const float& ExpiredTime, const int32& Index)
{
	RefreshRecordData(Index);
	FNEventRecord& Record = EventStore[Index];
	Record.Event = nullptr;
}

float UNTimelineDecorator::GetCurrentTime() const
{
	check(Timeline.IsValid());
	return Timeline->GetCurrentTime();
}

FName UNTimelineDecorator::GetLabel() const
{
	check(Timeline.IsValid());
	return Timeline->GetLabel();
}

UNTimelineEventDecorator* UNTimelineDecorator::CreateNewEvent(
	TSubclassOf<UNTimelineEventDecorator> Class, FName Name, float Duration, float Delay)
{
	UNTimelineEventDecorator* Object = UNTimelineEventDecoratorFactory::CreateObject<UNTimelineEventDecorator>(this, Class, Name);
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

void UNTimelineDecorator::Clear()
{
	EventStore.Empty();
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}

void UNTimelineDecorator::Serialize(FArchive& Ar)
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
	Ar << TickInterval;

	if (Ar.IsLoading())
	{
		Timeline->Clear();
		Timeline->SetLabel(Label);
		Timeline->SetTickInterval(TickInterval);
		Timeline->SetCurrentTime(CurrentTime);
	}

	if (EventStore.Num() > 0)
	{
		for (FNEventRecord& Record : EventStore)
		{
			Record.Serialize(Ar, this);
			if (Ar.IsLoading())
			{
				Timeline->SetTuple(UNTimelineDecorator::ConvertRecordToTuple(Record));
			}
		}
	}
}

void UNTimelineDecorator::BeginDestroy()
{
	EventStore.Empty();
	Timeline.Reset();
	Super::BeginDestroy();
}
