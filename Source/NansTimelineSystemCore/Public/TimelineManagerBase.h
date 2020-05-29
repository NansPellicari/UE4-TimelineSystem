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

class NTimelineInterface;

/** Enum for the NTimelineManagerBase::State */
enum class ENTimelineTimerState : uint8
{
	Played,
	Paused,
	Stopped
};

/**
 * This class is the client for the NTimelineInterface object.
 * Its goal is to decoupled client interface with timeline management.
 *
 * - NTimelineInterface manages time computation, notify events accordingly and save all states
 * - NTimelineManagerBase manages client controls.
 *
 * @see NTimeline
 */
class NANSTIMELINESYSTEMCORE_API NTimelineManagerBase
{
	friend class NTimelineInterface;

public:
	/** Calls the Init() method. */
	NTimelineManagerBase();

	/** Calls Clear() and release Timeline TSharedPtr */
	virtual ~NTimelineManagerBase();

	/**
	 * Instanciate the embeded NTimeline
	 *
	 * @param _TickInterval - Interval time between tick in sec
	 * @param _Label - Name of the Timeline.
	 */
	virtual void Init(float _TickInterval = 1.f, FName _Label = NAME_None);

	/** This pause the timeline ticking */
	virtual void Pause();

	/** This (re)start the timeline ticking */
	virtual void Play();

	/** This pause the timeline ticking and reset the NTimeline::CurrentTime to 0 */
	virtual void Stop();

	/** This checks the actual play state (ENTimelineTimerState) and tick the NTimelineInterface accordingly. */
	virtual void TimerTick();

	/** Get the actual state. */
	ENTimelineTimerState GetState() const;

	/** Get the tick interval which a timermanager should use to process */
	float GetTickInterval() const;

	/** Defined the desired ticking interval */
	virtual void SetTickInterval(float _TickInterval);

	/** Get the coupled NTimelineInterface */
	TSharedPtr<NTimelineInterface> GetTimeline() const;

protected:
	/** The interval retrieved from the timeline. */
	float TickInterval = 1.f;

	/** The actual state */
	ENTimelineTimerState State = ENTimelineTimerState::Stopped;

	/** Calls NTimeline::Clear()  */
	virtual void Clear();

	/**
	 * This should be used to make some checks right before ticking.
	 * So here you can manipulate State property to (not)allow ticking.
	 */
	virtual void onValidateTimelineTick() {}

	/** This method is call immediately before ticking */
	virtual void onNotifyTimelineTickBefore() {}

	/** This method is call immediately after ticking */
	virtual void onNotifyTimelineTickAfter() {}

	/** The coupled timeline */
	TSharedPtr<NTimelineInterface> Timeline;
};
