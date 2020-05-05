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

#pragma once

#include "CoreMinimal.h"

class NTimeline;

enum class ENTimelineTimerState : uint8
{
	Played,
	Paused,
	Stopped
};

class NANSTIMELINESYSTEMCORE_API NTimelineManagerAbstract
{
	friend class NTimeline;

public:
	NTimelineManagerAbstract();
	virtual ~NTimelineManagerAbstract();
	virtual void Pause();
	virtual void Play();
	virtual void Stop();

	void TimerTick();

	ENTimelineTimerState GetState();
	float GetTickInterval();
	TSharedPtr<NTimeline> GetTimeline();

protected:
	/**
	 * The interval retrieve from the timeline.
	 */
	float TickInterval;

	/**
	 * ENTimelineTimerState
	 */
	ENTimelineTimerState State = ENTimelineTimerState::Stopped;
	virtual void CreateTimeline();

	/**
	 * Only accept friend to use it.
	 * This to force their connection in derived class of NTimeline.
	 */
	void SetTimeline(NTimeline* _Timeline);
	virtual void Clear();
	virtual void onValidateTimelineTick() {}
	virtual void onNotifyTimelineTickBefore() {}
	virtual void onNotifyTimelineTickAfter() {}
	TSharedPtr<NTimeline> Timeline;
	void SetTickInterval(const float _TickInterval);
};
