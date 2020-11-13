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

class NTimelineManager;

/**
 * @see NTimelineInterface
 */
class NANSTIMELINESYSTEMCORE_API NTimeline : public NTimelineInterface
{
	friend class NTimelineManager;

public:
	/**
	 * A Timeline can't exists with a manager.
	 * This contructor garanties the necessary coupling & behavior consistancy.
	 *
	 * @param TimerManager - Timer which manage all time behavior (tick, pause, stop, play,...)
	 * @param _Label - (optionnal) The name of this timeline. If not provided it creates a name with a static incremented value.
	 */
	NTimeline(NTimelineManager* TimerManager, FName _Label = NAME_None);

	/** Empty events array */
	virtual ~NTimeline();

	/** @see OnExpired() */
	FNTimelineEventDelegate EventExpired;

	virtual FNTimelineEventDelegate& OnEventExpired() override;

	/**
	 * It creates a FEventTuple and calls BeforeOnAttached() to checks if it can be attached
	 * and AfterOnAttached() for any custom usages
	 *
	 * @param Event - The event you want to put in the timeline stream
	 */
	virtual bool Attached(TSharedPtr<NEventInterface> Event) override;

	/**
	 * Same as Attached(TSharedPtr<NEventInterface> Event) but for a collection of objects.
	 *
	 * @see NTimeline::Attached(TSharedPtr<NEventInterface> Event)
	 */
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) override;

	/**
	 * This should be called only by its friend NTimelineManager
	 * or a decorator to maintain consistency with its manager.
	 * @copydoc NTimelineInterface::SetTickInterval()
	 */
	virtual void SetTickInterval(float _TickInterval) override;

	virtual void SetCurrentTime(float _CurrentTime) override;
	virtual float GetCurrentTime() const override;

	/** Returns the FEventTuple collection */
	virtual const TArray<FNEventSave> GetEvents() const override;

	virtual void SetLabel(FName _Label) override;
	virtual FName GetLabel() const override;

	/**
	 * This should be used only to set data from an archive (save game).
	 * Prefer NTimeline::Attached() methods to set data during runtime.
	 *
	 * @param Tuple - Data which will be added to the Events TArray
	 */
	// void SetTuple(NTimeline::FEventTuple Tuple);

	/**
	 * This completely reset every events.
	 * It should be used with caution.
	 */
	virtual void Clear() override;

	/**
	 * @copydoc NTimelineInterface::NotifyTick()
	 * It uses internally GetTickInterval() to increment time.
	 */
	virtual void NotifyTick() override;
	virtual void PreDelete() override;
	virtual void Archive(FArchive& Ar) override;
	virtual TMap<FString, TSharedPtr<NEventInterface>> GetEventObjects() override;
	virtual TSharedPtr<NEventInterface> GetEvent(FString _UID) override;

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
	 * This is the value required by a timer manager to know
	 * the tick frequency for this timeline (given by NTimelineManager).
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
	 * Inside the tuple, the shared pointer is destroyed when event expires to avoid unnecessary memory allocations.
	 */
	TArray<FNEventSave> Events;
	TMap<FString, TSharedPtr<NEventInterface>> EventsObjects;

	/** only used for serialization */
	int32 EventsCount;
};
