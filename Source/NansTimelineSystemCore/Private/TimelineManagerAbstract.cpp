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

#include "TimelineManagerAbstract.h"

#include "Timeline.h"

NTimelineManagerAbstract::NTimelineManagerAbstract()
{
	Init();
}

NTimelineManagerAbstract::~NTimelineManagerAbstract()
{
	Clear();
	Timeline.Reset();
}

void NTimelineManagerAbstract::TimerTick()
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

TSharedPtr<NTimeline> NTimelineManagerAbstract::GetTimeline()
{
	return Timeline;
}

float NTimelineManagerAbstract::GetTickInterval()
{
	return TickInterval;
}

void NTimelineManagerAbstract::SetTickInterval(const float _TickInterval)
{
	TickInterval = _TickInterval;
}

void NTimelineManagerAbstract::Init(FName _Label)
{
	Timeline = MakeShareable(new NTimeline(this, _Label));
}

void NTimelineManagerAbstract::Play()
{
	// No reason for a timer to play without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Played;
}
void NTimelineManagerAbstract::Pause()
{
	// No reason for a timer to pause without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Paused;
}
void NTimelineManagerAbstract::Stop()
{
	Clear();
	State = ENTimelineTimerState::Stopped;
}

ENTimelineTimerState NTimelineManagerAbstract::GetState()
{
	return State;
}

void NTimelineManagerAbstract::Clear()
{
	if (Timeline.IsValid())
	{
		Timeline->Clear();
	}
}
