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

#include "Event/EventRecord.h"
#include "Event/UnrealEventProxy.h"
#include "Manager/TimelineManagerDecorator.h"
#include "NansTimelineSystemCore/Public/TimelineManager.h"

void UNTimelineDecorator::Init(UNTimelineManagerDecorator* TimelineManager, FName _Label)
{
	// TODO remove static cast, not useful anymore??
	Timeline = MakeShareable(new NTimeline(static_cast<NTimelineManager*>(TimelineManager), _Label));
}

void UNTimelineDecorator::SetTickInterval(float _TickInterval)
{
	if (!Timeline.IsValid()) return;
	Timeline->SetTickInterval(_TickInterval);
}

void UNTimelineDecorator::SetCurrentTime(float _CurrentTime)
{
	if (!Timeline.IsValid()) return;
	Timeline->SetCurrentTime(_CurrentTime);
}

void UNTimelineDecorator::SetLabel(FName _Label)
{
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

bool UNTimelineDecorator::Attached(TSharedPtr<NEventInterface> Event)
{
	return Timeline->Attached(Event);
}

void UNTimelineDecorator::Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection)
{
	Timeline->Attached(EventsCollection);
}

FNTimelineEventDelegate& UNTimelineDecorator::OnEventExpired()
{
	return Timeline->OnEventExpired();
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

UNEventDecorator* UNTimelineDecorator::CreateNewEvent(TSubclassOf<UNEventDecorator> Class, FName Name, float Duration, float Delay)
{
	static int32 Counter;
	if (Name == NAME_None)
	{
		FString EvtLabel = FString::Format(TEXT("EventDecorator_{0}"), {++Counter});
		Name = FName(*EvtLabel);
	}

	UNEventDecorator* Object = NewObject<UNEventDecorator>(this, Class, Name, EObjectFlags::RF_NoFlags);

	// TODO refacto: listen OnEventExpired for GCEvents.
	GCEvents.Add(Object);
	Object->Init(Name);
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
	GCEvents.Empty();
	StoreEventsUID.Empty();
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}

void UNTimelineDecorator::Serialize(FArchive& Ar)
{
	// Super::Serialize(Ar);
	if (!Timeline.IsValid()) return;
	if (Ar.IsSaving())
	{
		Timeline->GetEventObjects().GetKeys(StoreEventsUID);
	}

	Ar << StoreEventsUID;

	if (Ar.IsLoading())
	{
		GCEvents.Empty();
		Timeline->Clear();
	}

	Timeline->Archive(Ar);

	if (StoreEventsUID.Num() > 0)
	{
		// TODO refacto: test this!!!!!!!!!!!!!!!
		for (FString& UID : StoreEventsUID)
		{
			TSharedPtr<NEventInterface> Event;

			if (Ar.IsLoading())
			{
				TSharedPtr<NUnrealEventProxy> Proxy = MakeShareable(new NUnrealEventProxy());
				Proxy->ArchiveWithTimeline(Ar, this);
				Event = Proxy;
			}

			if (Ar.IsSaving()) Event = Timeline->GetEvent(UID);

			Event->Archive(Ar);

			if (Ar.IsLoading())
			{
				Timeline->Attached(Event);
			}
		}
	}
}

const TArray<FNEventSave> UNTimelineDecorator::GetEvents() const
{
	return Timeline->GetEvents();
}

void UNTimelineDecorator::PreDelete()
{
	Timeline->PreDelete();
}

void UNTimelineDecorator::Archive(FArchive& Ar)
{
	Timeline->Archive(Ar);
}

TMap<FString, TSharedPtr<NEventInterface>> UNTimelineDecorator::GetEventObjects()
{
	return Timeline->GetEventObjects();
}

TSharedPtr<NEventInterface> UNTimelineDecorator::GetEvent(FString _UID)
{
	return Timeline->GetEvent(_UID);
}

void UNTimelineDecorator::BeginDestroy()
{
	GCEvents.Empty();
	StoreEventsUID.Empty();
	if (Timeline.IsValid())
	{
		Timeline->PreDelete();
		Timeline.Reset();
	}
	Super::BeginDestroy();
}
