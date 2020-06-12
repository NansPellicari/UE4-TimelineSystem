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

DECLARE_MULTICAST_DELEGATE_TwoParams(FNEventDelegate, class NEventInterface*, const float&);

/**
 * An interface to manage events which can be attached to a timeline.
 */
class NANSTIMELINESYSTEMCORE_API NEventInterface
{
public:
	/** It indicates if the event expired. */
	virtual bool IsExpired() const = 0;
	/** Returns the localTime since the events has been attached (- delay) to a timeline */
	virtual const float GetLocalTime() const = 0;
	/** The time relative to the timeline this event has been attached to + its start delay. */
	virtual const float GetStartedAt() const = 0;
	/** The duration this event should live */
	virtual float GetDuration() const = 0;
	/** The delay before this event starts */
	virtual float GetDelay() const = 0;
	/** Retrieve the unique ID generated or given in ctor */
	virtual const FString GetUID() const = 0;
	/**
	 * This should be used only on serialization process
	 *
	 * @param _UId - Should be a unique FString, see ctor
	 */
	virtual void SetUID(FString _UId) = 0;
	/** Getter for Label */
	virtual const FName GetEventLabel() const = 0;
	/**
	 * This setter should be carrefully used,
	 * all the computation time should be calculated internally
	 * with the NotifyAddTime().
	 *
	 * @param _LocalTime - Time in secs
	 */
	virtual void SetLocalTime(float _LocalTime) = 0;
	/**
	 * A setter for the duration.
	 *
	 * @param _Duration - Time in secs
	 */
	virtual void SetDuration(float _Duration) = 0;
	/**
	 * A setter for the delay.
	 *
	 * @param _Delay - Time in secs
	 */
	virtual void SetDelay(float _Delay) = 0;

	/**
	 * A setter for the label.
	 *
	 * @param _EventLabel - A name to identify easily the event
	 */
	virtual void SetEventLabel(FName _EventLabel) = 0;
	/**
	 * This should be used only by NTimeline or serialization.
	 *
	 * @param StartTime - Time in secs
	 */
	virtual void Start(float StartTime) = 0;
	/**
	 * Increments LocalTime
	 * @param NewTime - in Millisecs
	 */
	virtual void NotifyAddTime(float NewTime) = 0;
	/** This should reset all data */
	virtual void Clear() = 0;
	/** @returns a FNTimelineEventDelegate ref which is broadcasted when an event expires. */
	virtual FNEventDelegate& OnStart() = 0;
};
