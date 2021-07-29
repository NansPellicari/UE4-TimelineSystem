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

FNTimelineManager::FNTimelineManager()
{
	Init();
}

FNTimelineManager::~FNTimelineManager()
{
	Timeline.Reset();
}

void FNTimelineManager::TimerTick()
{
	// No reason for a timer to tick without a timeline created
	check(Timeline.IsValid());

	OnValidateTimelineTick();
	if (State == ENTimelineTimerState::Played)
	{
		OnNotifyTimelineTickBefore();
		Timeline->NotifyTick();
		OnNotifyTimelineTickAfter();
	}
}

TSharedPtr<INTimelineInterface> FNTimelineManager::GetTimeline() const
{
	return Timeline;
}

ENTimelineTimerState FNTimelineManager::GetState() const
{
	return State;
}

float FNTimelineManager::GetTickInterval() const
{
	return TickInterval;
}

void FNTimelineManager::SetTickInterval(const float& InTickInterval)
{
	TickInterval = InTickInterval;
	if (Timeline.IsValid())
	{
		Timeline->SetTickInterval(InTickInterval);
	}
}

void FNTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Timeline = MakeShareable(new FNTimeline(*this, InLabel));
	TickInterval = InTickInterval;
	Timeline->SetTickInterval(TickInterval);
}

void FNTimelineManager::Play()
{
	// No reason for a timer to play without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Played;
}

void FNTimelineManager::Pause()
{
	// No reason for a timer to pause without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Paused;
}

void FNTimelineManager::Stop()
{
	Clear();
	State = ENTimelineTimerState::Stopped;
}

void FNTimelineManager::AddEvent(const TSharedPtr<INEventInterface>& Event)
{
	if (!Timeline.IsValid()) return;
	Timeline->Attached(Event);
}

TSharedPtr<INEventInterface> FNTimelineManager::CreateNewEvent(const FName& Name, const float& Duration,
	const float& Delay) const
{
	if (!Timeline.IsValid()) return nullptr;

	FName NewName = Name;

	if (NewName == NAME_None)
	{
		static int32 Counter;
		const FString EvtLabel = FString::Format(TEXT("EventView_{0}"), {++Counter});
		NewName = FName(*EvtLabel);
	}

	TSharedPtr<FNEvent> Object = MakeShareable(new FNEvent(NewName));
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

TSharedPtr<INEventInterface> FNTimelineManager::GetEvent(const FString& InUID) const
{
	return Timeline->GetEvent(InUID);
}

TArray<TSharedPtr<INEventInterface>> FNTimelineManager::GetEvents() const
{
	return Timeline->GetEvents();
}

void FNTimelineManager::PreDelete()
{
	Clear();

	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}

void FNTimelineManager::Archive(FArchive& Ar)
{
	if (Timeline.IsValid())
	{
		Timeline->Archive(Ar);
	}

	Ar << State;
	Ar << TickInterval;
}

void FNTimelineManager::Clear()
{
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}
