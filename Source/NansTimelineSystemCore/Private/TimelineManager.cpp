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
	if (Timeline != nullptr)
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

void NTimelineManager::Clear()
{
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}
