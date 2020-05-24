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

#include "Event/TimelineEventDecorator.h"

#include "NansTimelineSystemCore/Public/TimelineEventBase.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerBaseDecorator.h"

bool UNTimelineEventDecorator::IsExpired() const
{
	if (!Event.IsValid()) return true;
	return Event->IsExpired();
}

const float UNTimelineEventDecorator::GetLocalTime() const
{
	if (!Event.IsValid()) return LocalTime;
	return Event->GetLocalTime();
}

const float UNTimelineEventDecorator::GetStartedAt() const
{
	if (!Event.IsValid()) return StartedAt;
	return Event->GetStartedAt();
}

float UNTimelineEventDecorator::GetDuration() const
{
	if (!Event.IsValid()) return Duration;
	return Event->GetDuration();
}

void UNTimelineEventDecorator::Start(float StartTime)
{
	if (!Event.IsValid()) return;
	Event->Start(StartTime);
}

void UNTimelineEventDecorator::NotifyAddTime(float NewTime)
{
	if (!Event.IsValid()) return;
	Event->NotifyAddTime(NewTime);
}

float UNTimelineEventDecorator::GetDelay() const
{
	if (!Event.IsValid()) return Delay;
	return Event->GetDelay();
}

const FName UNTimelineEventDecorator::GetEventLabel() const
{
	if (!Event.IsValid()) return Label;
	return Event->GetEventLabel();
}

TSharedPtr<NTimelineEventBase> UNTimelineEventDecorator::GetEvent()
{
	return Event;
}

void UNTimelineEventDecorator::SetDelay(float _Delay)
{
	Event->Delay = _Delay;
}
void UNTimelineEventDecorator::SetDuration(float _Duration)
{
	Event->Duration = _Duration;
}

void UNTimelineEventDecorator::Init(FName _Label)
{
	Event = MakeShareable(new NTimelineEventBase(_Label));
}
void UNTimelineEventDecorator::BeginDestroy()
{
	Super::BeginDestroy();
	Event.Reset();
}

void UNTimelineEventDecorator::Serialize(FArchive& Ar)
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
T* UNTimelineEventDecorator::CreateObject(
	UObject* Outer, const TSubclassOf<UNTimelineEventDecorator> Class, FName Name, EObjectFlags Flags)
{
	static int32 Counter;
	if (Name == NAME_None)
	{
		FString EvtLabel = FString::Format(TEXT("EventDecorator_{0}"), {++Counter});
		Name = FName(*EvtLabel);
	}

	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Init(Name);
	return Obj;
}

template <typename T>
T* UNTimelineEventDecorator::CreateObjectFromEvent(UObject* Outer,
	const TSharedPtr<NTimelineEventBase> Object,
	const TSubclassOf<UNTimelineEventDecorator> Class,
	EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Event = Object;
	return Obj;
}
