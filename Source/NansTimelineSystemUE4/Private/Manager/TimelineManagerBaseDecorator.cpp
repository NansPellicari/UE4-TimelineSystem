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

#include "Manager/TimelineManagerBaseDecorator.h"

#include "Event/TimelineEventDecorator.h"
#include "Event/UnrealTimelineEventProxy.h"
#include "TimerManager.h"
#include "UnrealTimelineProxy.h"

UNTimelineManagerBaseDecorator::UNTimelineManagerBaseDecorator()
{
	MyTimeline = CreateDefaultSubobject<UNTimelineDecorator>(FName(TEXT("MyTimeline")));
	MyTimeline->Init(this);
	Timeline = MakeShareable(new UnrealTimelineProxy(*MyTimeline));
}

void UNTimelineManagerBaseDecorator::Init(float _TickInterval, FName _Label)
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNTimelineManagerBaseDecorator need a world to live"));
	TickInterval = _TickInterval;
	Timeline->SetTickInterval(_TickInterval);
	Timeline->SetLabel(_Label);
}

template <typename T>
T* UNTimelineManagerBaseDecorator::CreateObject(UObject* Outer, float TickInterval, FName _Label, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, NAME_None, Flags);
	Obj->Init(TickInterval, _Label);
	return Obj;
}
template <typename T>
T* UNTimelineManagerBaseDecorator::CreateObject(
	UObject* Outer, const UClass* Class, float TickInterval, FName _Label, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Init(TickInterval, _Label);
	return Obj;
}

float UNTimelineManagerBaseDecorator::GetCurrentTime() const
{
	return Timeline->GetCurrentTime();
}

void UNTimelineManagerBaseDecorator::Pause()
{
	NTimelineManagerBase::Pause();
}

void UNTimelineManagerBaseDecorator::Play()
{
	NTimelineManagerBase::Play();
}

void UNTimelineManagerBaseDecorator::Stop()
{
	NTimelineManagerBase::Stop();
}

void UNTimelineManagerBaseDecorator::SetTickInterval(float _TickInterval)
{
	NTimelineManagerBase::SetTickInterval(_TickInterval);
}

const TArray<FNEventRecord> UNTimelineManagerBaseDecorator::GetEvents() const
{
	return MyTimeline->GetAdaptedEvents();
}

FName UNTimelineManagerBaseDecorator::GetLabel() const
{
	return Timeline->GetLabel();
}

void UNTimelineManagerBaseDecorator::AddEvent(UNTimelineEventDecorator* Event)
{
	Timeline->Attached(MakeShareable(new UnrealTimelineEventProxy(*Event)));
}

UNTimelineEventDecorator* UNTimelineManagerBaseDecorator::CreateNewEvent(
	TSubclassOf<UNTimelineEventDecorator> Class, FName Name, float Duration, float Delay)
{
	if (MyTimeline == nullptr) return nullptr;
	return MyTimeline->CreateNewEvent(Class, Name, Duration, Delay);
}

UNTimelineEventDecorator* UNTimelineManagerBaseDecorator::CreateAndAddNewEvent(
	TSubclassOf<UNTimelineEventDecorator> Class, FName Name, float Duration, float Delay)
{
	UNTimelineEventDecorator* Object = CreateNewEvent(Class, Name, Duration, Delay);
	if (Object == nullptr) return nullptr;

	AddEvent(Object);
	return Object;
}

void UNTimelineManagerBaseDecorator::Serialize(FArchive& Ar)
{
	// Thanks to the UE4 serializing system, this will serialize all uproperty with "SaveGame"
	Super::Serialize(Ar);

	if (MyTimeline != nullptr)
	{
		MyTimeline->Serialize(Ar);
	}

	Ar << State;
	Ar << TickInterval;
}

void UNTimelineManagerBaseDecorator::BeginDestroy()
{
	if (MyTimeline != nullptr)
	{
		MyTimeline->ConditionalBeginDestroy();
	}
	Super::BeginDestroy();
}