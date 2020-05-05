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

#include "Manager/TimelineManagerBase.h"

#include "Manager/GameLifeTimelineManager.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "TimerManager.h"

UNTimelineManagerBase::UNTimelineManagerBase()
{
	check(GetOuter());
}

template <typename T>
T* UNTimelineManagerBase::CreateObject(UObject* Outer, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, NAME_None, Flags);
	Obj->Init();
	return Obj;
}
template <typename T>
T* UNTimelineManagerBase::CreateObject(UObject* Outer, const UClass* Class, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
	Obj->Init();
	return Obj;
}

void UNTimelineManagerBase::onNotifyTimelineTickBefore()
{
	Counter++;
}

void UNTimelineManagerBase::Clear()
{
	NTimelineManagerAbstract::Clear();
	Counter = 0;
}

void UNTimelineManagerBase::BeginDestroy()
{
	Super::BeginDestroy();
}

float UNTimelineManagerBase::GetTimelineTime()
{
	if (Timeline.IsValid())
	{
		return Timeline->GetCurrentTime();
	}
	return 0;
}

void UNTimelineManagerBase::Pause()
{
	NTimelineManagerAbstract::Pause();
}

void UNTimelineManagerBase::Play()
{
	NTimelineManagerAbstract::Play();
}

void UNTimelineManagerBase::Stop()
{
	NTimelineManagerAbstract::Stop();
}
