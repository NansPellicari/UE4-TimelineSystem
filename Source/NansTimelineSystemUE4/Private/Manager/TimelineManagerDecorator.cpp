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

#include "Event/EventDecorator.h"
#include "Event/UnrealEventProxy.h"
#include "TimerManager.h"
#include "UnrealTimelineProxy.h"

UNTimelineManagerDecorator::UNTimelineManagerDecorator()
{
	MyTimeline = CreateDefaultSubobject<UNTimelineDecorator>(FName(TEXT("MyTimeline")));
	MyTimeline->Init(this);
	Timeline = MakeShareable(new NUnrealTimelineProxy(*MyTimeline));
}

void UNTimelineManagerDecorator::Init(float _TickInterval, FName _Label)
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNTimelineManagerDecorator need a world to live"));
	TickInterval = _TickInterval;
	Timeline->SetTickInterval(_TickInterval);
	Timeline->SetLabel(_Label);
}

template <typename T>
T* UNTimelineManagerDecorator::CreateObject(UObject* Outer, float TickInterval, FName _Label, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, NAME_None, Flags);
	Obj->Init(TickInterval, _Label);
	return Obj;
}
template <typename T>
T* UNTimelineManagerDecorator::CreateObject(
	UObject* Outer, const UClass* Class, float TickInterval, FName _Label, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Init(TickInterval, _Label);
	return Obj;
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

const TArray<FNEventRecord> UNTimelineManagerDecorator::GetEvents() const
{
	return MyTimeline->GetAdaptedEvents();
}

FName UNTimelineManagerDecorator::GetLabel() const
{
	return Timeline->GetLabel();
}

void UNTimelineManagerDecorator::AddEvent(UNEventDecorator* Event)
{
	Timeline->Attached(MakeShareable(new NUnrealEventProxy(*Event)));
}

UNEventDecorator* UNTimelineManagerDecorator::CreateNewEvent(
	TSubclassOf<UNEventDecorator> Class, FName Name, float Duration, float Delay)
{
	if (MyTimeline == nullptr) return nullptr;
	return MyTimeline->CreateNewEvent(Class, Name, Duration, Delay);
}

UNEventDecorator* UNTimelineManagerDecorator::CreateAndAddNewEvent(
	TSubclassOf<UNEventDecorator> Class, FName Name, float Duration, float Delay)
{
	UNEventDecorator* Object = CreateNewEvent(Class, Name, Duration, Delay);
	if (Object == nullptr) return nullptr;

	AddEvent(Object);
	return Object;
}

void UNTimelineManagerDecorator::Serialize(FArchive& Ar)
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

void UNTimelineManagerDecorator::BeginDestroy()
{
	if (MyTimeline != nullptr)
	{
		MyTimeline->ConditionalBeginDestroy();
	}
	Super::BeginDestroy();
}
