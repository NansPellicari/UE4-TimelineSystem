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

#include "TimelineManager.h"


#include "Event.h"
#include "Timeline.h"
#include "Math/UnitConversion.h"
#include "Programs/UnrealLightmass/Private/ImportExport/3DVisualizer.h"
#include "Programs/UnrealLightmass/Private/ImportExport/3DVisualizer.h"
#include "Programs/UnrealLightmass/Private/ImportExport/3DVisualizer.h"
#include "Programs/UnrealLightmass/Private/ImportExport/3DVisualizer.h"

NTimelineManager::NTimelineManager()
{
	Init();
}

NTimelineManager::~NTimelineManager()
{
	Timeline.Reset();
}

void NTimelineManager::TimerTick()
{
	// No reason for a timer to tick without a timeline created
	check(Timeline.IsValid());

	onValidateTimelineTick();
	if (State == ENTimelineTimerState::Played)
	{
		onNotifyTimelineTickBefore();
		Timeline->NotifyTick();
		onNotifyTimelineTickAfter();
	}
}

TSharedPtr<NTimelineInterface> NTimelineManager::GetTimeline() const
{
	return Timeline;
}

ENTimelineTimerState NTimelineManager::GetState() const
{
	return State;
}

float NTimelineManager::GetTickInterval() const
{
	return TickInterval;
}

void NTimelineManager::SetTickInterval(float _TickInterval)
{
	TickInterval = _TickInterval;
	if (Timeline.IsValid())
	{
		Timeline->SetTickInterval(_TickInterval);
	}
}

void NTimelineManager::Init(float _TickInterval, FName _Label)
{
	Timeline = MakeShareable(new NTimeline(this, _Label));
	TickInterval = _TickInterval;
	Timeline->SetTickInterval(TickInterval);
}

void NTimelineManager::Play()
{
	// No reason for a timer to play without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Played;
}

void NTimelineManager::Pause()
{
	// No reason for a timer to pause without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Paused;
}

void NTimelineManager::Stop()
{
	Clear();
	State = ENTimelineTimerState::Stopped;
}

void NTimelineManager::AddEvent(TSharedPtr<NEventInterface> Event)
{
	if (!Timeline.IsValid()) return;
	Timeline->Attached(Event);
}

TSharedPtr<NEventInterface> NTimelineManager::CreateNewEvent(FName Name, float Duration, float Delay) const
{
	static int32 Counter;
	if (!Timeline.IsValid()) return nullptr;

	if (Name == NAME_None)
	{
		const FString EvtLabel = FString::Format(TEXT("EventView_{0}"), {++Counter});
		Name = FName(*EvtLabel);
	}
	TSharedPtr<NEvent> Object = MakeShareable(new NEvent(Name));
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

TSharedPtr<NEventInterface> NTimelineManager::GetEvent(FString _UID)
{
	return Timeline->GetEvent(_UID);
}

const TArray<TSharedPtr<NEventInterface>> NTimelineManager::GetEvents() const
{
	return Timeline->GetEvents();
}

void NTimelineManager::PreDelete()
{
	Clear();

	if (Timeline.IsValid())
	{
		Timeline->PreDelete();
	}
}

void NTimelineManager::Archive(FArchive& Ar)
{
	if (Timeline.IsValid())
	{
		Timeline->Archive(Ar);
	}

	Ar << State;
	Ar << TickInterval;
}


void NTimelineManager::Clear()
{
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}
