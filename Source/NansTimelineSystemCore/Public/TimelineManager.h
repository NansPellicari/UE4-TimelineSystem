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

class INEventInterface;
class INTimelineInterface;

/** Enum for the NTimelineManager::State */
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
 * - NTimelineManager manages client controls.
 *
 * @see NTimelineInterface
 * @see NTimeline
 */
class NANSTIMELINESYSTEMCORE_API FNTimelineManager
{
	friend class INTimelineInterface;

public:
	/** Calls the Init() method. */
	FNTimelineManager();

	/** Calls Clear() and release Timeline TSharedPtr */
	virtual ~FNTimelineManager();

	/**
	 * Instantiate the embedded NTimeline
	 *
	 * @param InTickInterval - Interval time between tick in sec
	 * @param InLabel - Name of the Timeline.
	 */
	virtual void Init(const float& InTickInterval = 1.f, const FName& InLabel = NAME_None);

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

	/** Get the tick interval which a timeline manager should use to process */
	float GetTickInterval() const;

	/** Defined the desired ticking interval */
	virtual void SetTickInterval(const float& InTickInterval);

	/** Get the coupled NTimelineInterface */
	TSharedPtr<INTimelineInterface> GetTimeline() const;

	/**
	* Adds an event to the timeline object,
	* it works as a pass-through for UNTimelineDecorator::Attached(UNEventView* Event)
	*
	* @param Event - An Event object you want to saved to the associated timeline.
	*/
	virtual void AddEvent(const TSharedPtr<INEventInterface>& Event);

	/**
	* Creates a new Event and use this timeline as the outer for this new object.
	*
	* @param Name - The label of the event, can be useful for user stats & feedback
	* @param Duration - The time this event is active, 0 to almost INFINI (0 means undetermined time)
	* @param Delay - The time before this event start being active, 0 to almost INFINI (0 means "right now")
	*/
	virtual TSharedPtr<INEventInterface> CreateNewEvent(const FName& Name, const float& Duration = 0.f,
		const float& Delay = 0.f) const;

	TSharedPtr<INEventInterface> GetEvent(const FString& InUID) const;
	TArray<TSharedPtr<INEventInterface>> GetEvents() const;
	virtual void PreDelete();
	virtual void Archive(FArchive& Ar);

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
	virtual void OnValidateTimelineTick() {}

	/** This method is call immediately before ticking */
	virtual void OnNotifyTimelineTickBefore() {}

	/** This method is call immediately after ticking */
	virtual void OnNotifyTimelineTickAfter() {}

	/** The coupled timeline */
	TSharedPtr<INTimelineInterface> Timeline;
};
