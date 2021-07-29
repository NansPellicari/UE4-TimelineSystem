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

#include "Timeline.h"
#include "Event/EventView.h"

UNTimelineManagerDecorator::UNTimelineManagerDecorator()
{
	Timeline = MakeShareable(new FNTimeline(*this, FName(TEXT("MyTimeline"))));
}

void UNTimelineManagerDecorator::Init(const float& InTickInterval, const FName& InLabel)
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNTimelineManagerDecorator need a world to live"));
	TickInterval = InTickInterval;
	Timeline->SetTickInterval(InTickInterval);
	Timeline->SetLabel(InLabel);
}

float UNTimelineManagerDecorator::GetCurrentTime() const
{
	return Timeline->GetCurrentTime();
}

void UNTimelineManagerDecorator::Pause()
{
	FNTimelineManager::Pause();
}

void UNTimelineManagerDecorator::Play()
{
	FNTimelineManager::Play();
}

void UNTimelineManagerDecorator::Stop()
{
	FNTimelineManager::Stop();
}

void UNTimelineManagerDecorator::SetTickInterval(const float& InTickInterval)
{
	FNTimelineManager::SetTickInterval(InTickInterval);
}

TArray<UNEventView*> UNTimelineManagerDecorator::GetEventViews() const
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

UNEventView* UNTimelineManagerDecorator::GetEventView(const FString& InUID)
{
	auto Event = NewObject<UNEventView>();
	Event->Init(GetEvent(InUID));
	return Event;
}

FName UNTimelineManagerDecorator::GetLabel() const
{
	return Timeline->GetLabel();
}

void UNTimelineManagerDecorator::CreateAndAddNewEvent(FName Name, float Duration, float Delay)
{
	const TSharedPtr<INEventInterface> Object = CreateNewEvent(Name, Duration, Delay);
	if (!Object.IsValid()) return;

	FNTimelineManager::AddEvent(Object);
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
