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

#include "Event/TimelineEventAdapter.h"

#include "NansTimelineSystemCore/Public/TimelineEventBase.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerBaseAdapter.h"

bool UNTimelineEventAdapter::IsExpired() const
{
	if (!Event.IsValid()) return true;
	return Event->IsExpired();
}

const float UNTimelineEventAdapter::GetLocalTime() const
{
	if (!Event.IsValid()) return LocalTime;
	return Event->GetLocalTime();
}

const float UNTimelineEventAdapter::GetStartedAt() const
{
	if (!Event.IsValid()) return StartedAt;
	return Event->GetStartedAt();
}

float UNTimelineEventAdapter::GetDuration() const
{
	if (!Event.IsValid()) return Duration;
	return Event->GetDuration();
}

void UNTimelineEventAdapter::Start(float StartTime)
{
	if (!Event.IsValid()) return;
	Event->Start(StartTime);
}

void UNTimelineEventAdapter::NotifyAddTime(float NewTime)
{
	if (!Event.IsValid()) return;
	Event->NotifyAddTime(NewTime);
}

float UNTimelineEventAdapter::GetDelay() const
{
	if (!Event.IsValid()) return Delay;
	return Event->GetDelay();
}

const FName UNTimelineEventAdapter::GetEventLabel() const
{
	if (!Event.IsValid()) return Label;
	return Event->GetEventLabel();
}

TSharedPtr<NTimelineEventBase> UNTimelineEventAdapter::GetEvent()
{
	return Event;
}

void UNTimelineEventAdapter::SetDelay(float _Delay)
{
	Event->Delay = _Delay;
}
void UNTimelineEventAdapter::SetDuration(float _Duration)
{
	Event->Duration = _Duration;
}

void UNTimelineEventAdapter::Init(FName _Label)
{
	Event = MakeShareable(new NTimelineEventBase(_Label));
}
void UNTimelineEventAdapter::BeginDestroy()
{
	Super::BeginDestroy();
	Event.Reset();
}

void UNTimelineEventAdapter::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (Ar.IsSaving() && Event.IsValid())
	{
		Label = Event->Label;
		LocalTime = Event->LocalTime;
		StartedAt = Event->StartedAt;
		Duration = Event->Duration;
		Delay = Event->Delay;
	}

	Ar << Label;
	Ar << LocalTime;
	Ar << StartedAt;
	Ar << Duration;
	Ar << Delay;

	if (Ar.IsLoading() && !Event.IsValid())
	{
		Init(Label);
	}

	if (Event.IsValid())
	{
		Event->Label = Label;
		Event->LocalTime = LocalTime;
		Event->StartedAt = StartedAt;
		Event->Duration = Duration;
		Event->Delay = Delay;
		Clear();
	}
}

template <typename T>
T* UNTimelineEventAdapter::CreateObject(
	UObject* Outer, const TSubclassOf<UNTimelineEventAdapter> Class, FName Name, EObjectFlags Flags)
{
	static int32 Counter;
	if (Name == NAME_None)
	{
		FString EvtLabel = FString::Format(TEXT("EventAdapter_{0}"), {++Counter});
		Name = FName(*EvtLabel);
	}

	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Init(Name);
	return Obj;
}

template <typename T>
T* UNTimelineEventAdapter::CreateObjectFromEvent(UObject* Outer,
	const TSharedPtr<NTimelineEventBase> Object,
	const TSubclassOf<UNTimelineEventAdapter> Class,
	EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Event = Object;
	return Obj;
}
