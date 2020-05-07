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
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerBase.h"

bool UNTimelineEventAdapter::IsExpired() const
{
	return Event->IsExpired();
}

const float UNTimelineEventAdapter::GetLocalTime() const
{
	return Event->GetLocalTime();
}

const float UNTimelineEventAdapter::GetStartedAt() const
{
	return Event->GetStartedAt();
}

float UNTimelineEventAdapter::GetDuration() const
{
	return Event->GetDuration();
}

void UNTimelineEventAdapter::Start(float StartTime)
{
	Event->Start(StartTime);
}

void UNTimelineEventAdapter::NotifyAddTime(float NewTime)
{
	Event->NotifyAddTime(NewTime);
}

float UNTimelineEventAdapter::GetDelay() const
{
	return Event->GetDelay();
}

const FName UNTimelineEventAdapter::GetEventLabel() const
{
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

void UNTimelineEventAdapter::BeginDestroy()
{
	Super::BeginDestroy();
	Event.Reset();
}

template <typename T>
T* UNTimelineEventAdapter::CreateObject(
	UObject* Outer, const TSubclassOf<UNTimelineEventAdapter> Class, FName Name, EObjectFlags Flags)
{
	static int32 Counter;
	if (Name == NAME_None)
	{
		FString EvtLabel = FString::Format(TEXT("EventAdapter_{0}"), {Counter++});
		Name = FName(*EvtLabel);
	}

	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Event = MakeShareable(new NTimelineEventBase(Name));
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
