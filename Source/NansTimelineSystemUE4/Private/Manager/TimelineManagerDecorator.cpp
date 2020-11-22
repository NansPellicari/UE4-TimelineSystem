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

#include "Manager/TimelineManagerDecorator.h"

#include "Event/EventView.h"
#include "TimerManager.h"

UNTimelineManagerDecorator::UNTimelineManagerDecorator()
{
	Timeline = MakeShareable(new NTimeline(static_cast<NTimelineManager*>(this), FName(TEXT("MyTimeline"))));
}

void UNTimelineManagerDecorator::Init(float _TickInterval, FName _Label)
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNTimelineManagerDecorator need a world to live"));
	TickInterval = _TickInterval;
	Timeline->SetTickInterval(_TickInterval);
	Timeline->SetLabel(_Label);
}

float UNTimelineManagerDecorator::GetCurrentTime() const
{
	return Timeline->GetCurrentTime();
}

void UNTimelineManagerDecorator::Pause()
{
	NTimelineManager::Pause();
}

void UNTimelineManagerDecorator::Play()
{
	NTimelineManager::Play();
}

void UNTimelineManagerDecorator::Stop()
{
	NTimelineManager::Stop();
}

void UNTimelineManagerDecorator::SetTickInterval(float _TickInterval)
{
	NTimelineManager::SetTickInterval(_TickInterval);
}

const TArray<UNEventView*> UNTimelineManagerDecorator::GetEventViews() const
{
	TArray<UNEventView*> EventRecords;
	for (auto& Event : GetEvents())
	{
		auto EventView = NewObject<UNEventView>();
		EventView->Init(Event);
		EventRecords.Add(EventView);
	}
	return EventRecords;
}

UNEventView* UNTimelineManagerDecorator::GetEventView(FString _UID)
{
	auto Event = NewObject<UNEventView>();
	Event->Init(GetEvent(_UID));
	return Event;
}

FName UNTimelineManagerDecorator::GetLabel() const
{
	return Timeline->GetLabel();
}


void UNTimelineManagerDecorator::CreateAndAddNewEvent(
	FName Name, float Duration, float Delay)
{
	TSharedPtr<NEventInterface> Object = CreateNewEvent(Name, Duration, Delay);
	if (!Object.IsValid()) return;

	NTimelineManager::AddEvent(Object);
}

void UNTimelineManagerDecorator::Serialize(FArchive& Ar)
{
	// Thanks to the UE4 serializing system, this will serialize all uproperty with "SaveGame"
	Super::Serialize(Ar);
	Archive(Ar);
}

void UNTimelineManagerDecorator::BeginDestroy()
{
	PreDelete();
	Super::BeginDestroy();
}
