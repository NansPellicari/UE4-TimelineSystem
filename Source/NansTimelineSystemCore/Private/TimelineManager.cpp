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

#include "Timeline.h"
#include "Math/UnitConversion.h"

FNTimelineManager::FNTimelineManager() : Timeline(MakeShared<FNTimeline>()) {}

FNTimelineManager::~FNTimelineManager() {}

void FNTimelineManager::TimerTick()
{
	OnValidateTimelineTick();
	if (State == ENTimelineTimerState::Played)
	{
		OnNotifyTimelineTickBefore();
		Timeline->NotifyTick();
		OnNotifyTimelineTickAfter();
	}
}

TSharedPtr<FNTimeline> FNTimelineManager::GetTimeline() const
{
	return Timeline;
}

ENTimelineTimerState FNTimelineManager::GetState() const
{
	return State;
}

void FNTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Timeline->SetTickInterval(InTickInterval);
	if (InLabel != NAME_None)
	{
		Timeline->SetLabel(InLabel);
	}
}

void FNTimelineManager::Play()
{
	State = ENTimelineTimerState::Played;
}

void FNTimelineManager::Pause()
{
	State = ENTimelineTimerState::Paused;
}

void FNTimelineManager::Stop()
{
	Timeline->Clear();
	State = ENTimelineTimerState::Stopped;
}

TSharedPtr<FNEvent> FNTimelineManager::CreateNewEvent(const FName& Name, const float& Duration,
	const float& Delay) const
{
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

void FNTimelineManager::Clear()
{
	Timeline->Clear();
}

FNTimelineEventDelegate& FNTimelineManager::OnEventChanged() const
{
	return Timeline->EventChanged;
}

void FNTimelineManager::Archive(FArchive& Ar)
{
	Timeline->Archive(Ar);
	Ar << State;
}
