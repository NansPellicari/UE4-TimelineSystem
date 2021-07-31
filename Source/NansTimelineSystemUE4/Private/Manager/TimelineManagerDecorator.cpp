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

UNTimelineManagerDecorator::UNTimelineManagerDecorator() : FNTimelineManager() {}

void UNTimelineManagerDecorator::Init(const float& InTickInterval, const FName& InLabel)
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNTimelineManagerDecorator need a world to live"));
	TickInterval = InTickInterval;
	FNTimelineManager::Init(InTickInterval, InLabel);

	OnEventChanged().AddUObject(this, &UNTimelineManagerDecorator::OnEventChangedDelegate);
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

void UNTimelineManagerDecorator::OnEventChangedDelegate(TSharedPtr<FNEvent> Event,
	const ENTimelineEvent& EventName, const float& ExpiredTime, const int32& Index)
{
	auto EventView = NewObject<UNEventView>();
	EventView->Init(Event);
	OnBPEventChanged(EventView, ExpiredTime);
}

TArray<UNEventView*> UNTimelineManagerDecorator::GetEventViews() const
{
	TArray<UNEventView*> EventRecords;
	for (auto& Event : GetTimeline()->GetEvents())
	{
		auto EventView = NewObject<UNEventView>();
		EventView->Init(Event);
		EventRecords.Add(EventView);
	}
	return EventRecords;
}

UNEventView* UNTimelineManagerDecorator::GetEventView(const FString& InUID)
{
	UNEventView* EventView = NewObject<UNEventView>();
	const TSharedPtr<FNEvent> Event = GetTimeline()->GetEvent(InUID);
	if (!Event.IsValid()) return nullptr;
	EventView->Init(Event);
	return EventView;
}

float UNTimelineManagerDecorator::GetCurrentTime() const
{
	return GetTimeline()->GetCurrentTime();
}

FName UNTimelineManagerDecorator::GetLabel() const
{
	return GetTimeline()->GetLabel();
}

void UNTimelineManagerDecorator::SetLabel(const FName& Name)
{
	GetTimeline()->SetLabel(Name);
}

void UNTimelineManagerDecorator::CreateAndAddNewEvent(FName Name, float Duration, float Delay)
{
	const TSharedPtr<FNEvent> Object = CreateNewEvent(Name, Duration, Delay);
	if (!Object.IsValid()) return;

	GetTimeline()->Attached(Object);
}

void UNTimelineManagerDecorator::Serialize(FArchive& Ar)
{
	// Thanks to the UE4 serializing system, this will serialize all uproperty with "SaveGame"
	Super::Serialize(Ar);
	Archive(Ar);
}

void UNTimelineManagerDecorator::BeginDestroy()
{
	OnEventChanged().RemoveAll(this);
	Clear();
	Super::BeginDestroy();
}
