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
#include "EventInterface.h"
#include "TimelineInterface.h"

DECLARE_DELEGATE_ThreeParams(FEventDelegate, TSharedPtr<NEventInterface>, const float&, const int32&);

class NTimelineManager;

/**
 * Its goal is to saved events and place them in time.
 * It works as a Time & Event container.
 * The NTimelineManager class is dedicated to handle it.
 *
 * @see ./TimelineManager.h
 */
class NANSTIMELINESYSTEMCORE_API NTimeline : public NTimelineInterface
{
	friend class NTimelineManager;

public:
	/**
	 * An event tuple is an event representation,
	 * it allows to keep important details trace in memory.
	 * 0: Event object
	 * 1: attached time
	 * 2: delay
	 * 3: duration
	 * 4: label
	 * 5: expired time
	 */
	using FEventTuple = TTuple<TSharedPtr<NEventInterface>, float, const float, const float, const FName, float>;

	/**
	 * A Timeline can't exists with a manager.
	 * This contructor garanties the necessary coupling & behavior consistancy.
	 *
	 * @param TimerManager - Timer which manage all time behavior (tick, pause, stop, play,...)
	 * @param _Label - (optionnal) The name of this timeline. If not provided it creates a name with a static incremented value.
	 */
	NTimeline(NTimelineManager* TimerManager, FName _Label = NAME_None);

	/** Calls Clear() */
	virtual ~NTimeline();

	/** @see OnExpired() */
	FEventDelegate EventExpired;

	/** It creates a FEventTuple and calls BeforeOnAttached() to checks if it can be attached
	 * and AfterOnAttached() for any custom usages
	 *
	 * @param Event - The event you want to put in the timeline stream
	 */
	virtual bool Attached(TSharedPtr<NEventInterface> Event);

	/**
	 * Same as Attached(TSharedPtr<NEventInterface> Event) but for a collection of objects.
	 */
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection);

	/**
	 * This should be called only by its friend NTimelineManager
	 * or a decorator to maintain consistency with its manager.
	 */
	virtual void SetTickInterval(float _TickInterval);

	/** This method is mainly used for savegame serialization */
	virtual void SetCurrentTime(float _CurrentTime);

	/** Get CurrentTime */
	virtual float GetCurrentTime() const;

	/** Returns the FEventTuple collection */
	const TArray<NTimeline::FEventTuple> GetEvents() const;

	/**
	 * Give a name to this timeline
	 * @param _Label - The name
	 */
	virtual void SetLabel(FName _Label);

	/** Return the actual name */
	virtual FName GetLabel() const;

	/**
	 * This should be used only to set data from an archive (save game).
	 * Prefer NTimeline::Attached() methods to set data during runtime.
	 *
	 * @param Tuple - Data which will be added to the Events TArray
	 */
	void SetTuple(NTimeline::FEventTuple Tuple);

	/**
	 * This completely reset every events.
	 * It should be used with caution.
	 */
	virtual void Clear();

	/**
	 * This manages to notify every events saved in this timeline with the new time added.
	 * It uses internally GetTickInterval() to increment time.
	 */
	virtual void NotifyTick();

protected:
	/** The name of this timeline */
	FName Label;

	/**
	 * Tick interval, should be set by its manager
	 */
	float TickInterval = 1.f;

	/**
	 * It is computed internally in the NotifyTick() method.
	 * In every tick it adds GetTickInterval() return.
	 */
	float CurrentTime = 0.f;

	/**
	 * This to allow inherited adapters to have a default constructor
	 */
	NTimeline(){};

	/** In case of specialisation needs to avoid the attach process in some cases */
	virtual bool BeforeOnAttached(TSharedPtr<NEventInterface> Event, const float AttachedTime)
	{
		return true;
	};

	/** If needed to make some stats, analytics, trigger error,... */
	virtual void AfterOnAttached(TSharedPtr<NEventInterface> Event, const float AttachedTime) {}

	/**
	 * This is the value required by a timer to know
	 * the tick frequency for this timeline.
	 * The NotifyTick use this method to add time on CurrentTime
	 * at each call.
	 */
	virtual const float GetTickInterval() const;

	/**
	 * Use Event SharedPtr with caution, it's pointer is reset just after this method is called.
	 * @warning the Event should be used internally only to avoid nullptr reference
	 */
	virtual void OnExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index);

private:
	/**
	 * Collection of each Events attached to the timeline.
	 * These event tuples are made to keep traces of what happens during game sessions.
	 * They could be used for stats or user feedbacks for instance.
	 * > Important notes:
	 * Inside the tuple, the shared pointer is destroyed to avoid memory leaks on NotifyTick().
	 */
	TArray<FEventTuple> Events;
};
