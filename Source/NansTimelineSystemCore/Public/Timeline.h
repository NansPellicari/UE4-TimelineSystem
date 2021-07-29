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

struct FNEventSave;
class FNTimelineManager;

/**
 * @see NTimelineInterface
 */
class NANSTIMELINESYSTEMCORE_API FNTimeline final : public INTimelineInterface
{
	friend class FNTimelineManager;

public:
	/**
	 * A Timeline can't exists with a manager.
	 * This constructor guaranties the necessary coupling & behavior consistency.
	 *
	 * @param TimelineManager - Timer which manage all time behavior (tick, pause, stop, play,...)
	 * @param InLabel - (optional) The name of this timeline. If not provided it creates a name with a static incremented value.
	 */
	FNTimeline(FNTimelineManager& TimelineManager, const FName& InLabel = NAME_None);

	/** Empty events array */
	virtual ~FNTimeline() override;

	/** @see OnExpired() */
	FNTimelineEventDelegate EventChanged;

	virtual FNTimelineEventDelegate& OnEventChanged() override;

	/**
	 * It creates a FEventTuple and calls BeforeOnAttached() to checks if it can be attached
	 * and AfterOnAttached() for any custom usages
	 *
	 * @param Event - The event you want to put in the timeline stream
	 */
	virtual bool Attached(const TSharedPtr<INEventInterface>& Event) override;

	/**
	 * Same as Attached(TSharedPtr<NEventInterface> Event) but for a collection of objects.
	 *
	 * @see NTimeline::Attached(TSharedPtr<NEventInterface> Event)
	 */
	virtual void Attached(const TArray<TSharedPtr<INEventInterface>>& EventsCollection) override;

	/**
	 * This should be called only by its friend NTimelineManager
	 * or a decorator to maintain consistency with its manager.
	 * @copydoc INTimelineInterface::SetTickInterval()
	 */
	virtual void SetTickInterval(const float& InTickInterval) override;

	virtual void SetCurrentTime(const float& InCurrentTime) override;
	virtual float GetCurrentTime() const override;

	virtual void SetLabel(const FName& InLabel) override;
	virtual FName GetLabel() const override;

	/**
	 * This completely reset every events.
	 * It should be used with caution.
	 */
	virtual void Clear() override;

	/**
	 * @copydoc INTimelineInterface::NotifyTick()
	 * It uses internally GetTickInterval() to increment time.
	 */
	virtual void NotifyTick() override;
	virtual void Archive(FArchive& Ar) override;
	virtual TArray<TSharedPtr<INEventInterface>> GetEvents() const override;
	virtual TSharedPtr<INEventInterface> GetEvent(const FString& InUID) const override;

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
	FNTimeline() {};

	/**
	 * This is the value required by a timer manager to know
	 * the tick frequency for this timeline (given by NTimelineManager).
	 * The NotifyTick use this method to add time on CurrentTime
	 * at each call.
	 */
	float GetTickInterval() const;

	/**
	 * Use Event SharedPtr with caution, it's pointer is reset just after this method is called.
	 * @warning the Event should be used internally only to avoid nullptr reference
	 */
	void OnExpired(const TSharedPtr<INEventInterface>& Event, const float& ExpiredTime, const int32& Index);

private:
	/**
	 * Collection of each Events attached to the timeline.
	 * These event structs are made to keep traces of what happens during game sessions.
	 * They could be used for stats or user feedbacks for instance.
	 * > Important notes:
	 * Inside the struct, the shared pointer is destroyed when event expires to avoid unnecessary memory allocations.
	 */
	TArray<FNEventSave> SavedEvents;
	TMap<FString, TSharedPtr<INEventInterface>> Events;
};
