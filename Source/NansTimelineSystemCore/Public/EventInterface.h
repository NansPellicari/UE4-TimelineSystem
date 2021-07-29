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

DECLARE_MULTICAST_DELEGATE_TwoParams(FNEventDelegate, class INEventInterface*, const float&);

struct NANSTIMELINESYSTEMCORE_API FNEventSave
{
	FNEventSave() {}

	FNEventSave(const FString& InUID, const float& InAttachedTime, const float& InDelay, const float& InDuration,
		const FName& InLabel, const float& InExpiredTime)
		: UID(InUID),
		  AttachedTime(InAttachedTime),
		  Delay(InDelay),
		  Duration(InDuration),
		  Label(InLabel),
		  ExpiredTime(InExpiredTime) { }

	FString UID;
	float AttachedTime = -1.f;
	float Delay = 0.f;
	float Duration = 0.f;
	FName Label = NAME_None;
	float ExpiredTime = -1.f;
	float StartedAt = -1.f;
	float LocalTime = 0.f;
	// TODO add this possibility later
	// TArray<uint8> ExtraData

	friend FArchive& operator<<(FArchive& Ar, FNEventSave& Record)
	{
		Ar << Record.UID;
		Ar << Record.AttachedTime;
		Ar << Record.Delay;
		Ar << Record.Duration;
		Ar << Record.Label;
		Ar << Record.ExpiredTime;
		Ar << Record.LocalTime;
		Ar << Record.StartedAt;

		return Ar;
	};
};

/**
 * An interface to manage events which can be attached to a timeline.
 */
class NANSTIMELINESYSTEMCORE_API INEventInterface
{
public:
	virtual ~INEventInterface() {}

	/** It indicates if the event expired. */
	virtual bool IsExpired() const = 0;

	/** Returns the localTime since the events has been attached (+ delay if > 0) to a timeline */
	virtual float GetLocalTime() const = 0;

	/** The time relative to the timeline this event has been attached to. */
	virtual float GetAttachedTime() const = 0;

	/** The time relative to the timeline this event has been attached to + its start delay. */
	virtual float GetStartedAt() const = 0;

	/** The duration this event should live */
	virtual float GetDuration() const = 0;

	/** The delay before this event starts */
	virtual float GetDelay() const = 0;

	/** Retrieve the unique ID generated or given in ctor */
	virtual FString GetUID() const = 0;

	/**
	 * The time relative to the timeline this event has been expired,
	 * should return -1 if this event has no duration.
	 */
	virtual float GetExpiredTime() const = 0;

	/**
	 * This should be used only on serialization process
	 *
	 * @param InUId - Should be a unique FString, see ctor
	 */
	virtual void SetUID(const FString& InUId) = 0;

	/** Getter for Label */
	virtual FName GetEventLabel() const = 0;

	/** Set the time this event is attached to timeline, should be used only by a FNTimeline. */
	virtual void SetAttachedTime(const float& InLocalTime) = 0;

	/**
	 * This can be useful to avoid an Event to be attached to a timeline.
	 * @see FNTimeline::Attached()
	 * @see ENTimelineEvent::BeforeAttached
	 * @param bInIsAttachable - boolean to defined is attachable capability
	 */
	virtual void SetAttachable(const bool& bInIsAttachable) = 0;

	/** Timeline use this to know if this event can be attached on. */
	virtual bool IsAttachable() const = 0;

	/**
	 * Set the expired time for this event.
	 * It is called by the FNTimeline.
	 * @param InLocalTime - the time relative to the timeline
	 */
	virtual void SetExpiredTime(const float& InLocalTime) = 0;

	/**
	 * This setter should be carefully used,
	 * all the computation time should be calculated internally
	 * with the NotifyAddTime().
	 *
	 * @param InLocalTime - Time in secs
	 */
	virtual void SetLocalTime(const float& InLocalTime) = 0;
	/**
	 * A setter for the duration.
	 *
	 * @param InDuration - Time in secs
	 */
	virtual void SetDuration(const float& InDuration) = 0;

	/**
	 * A setter for the delay.
	 *
	 * @param InDelay - Time in secs
	 */
	virtual void SetDelay(const float& InDelay) = 0;

	/**
	 * A setter for the label.
	 *
	 * @param InEventLabel - A name to identify easily the event
	 */
	virtual void SetEventLabel(const FName& InEventLabel) = 0;

	/**
	 * This should be used only by NTimeline or serialization.
	 *
	 * @param StartTime - Time in secs
	 */
	virtual void Start(const float& StartTime) = 0;

	/**
	 * This can stop the event and make it expires to its next tick.
	 */
	virtual void Stop() = 0;

	/**
	 * Increments LocalTime
	 * @param NewTime - in Millisecs
	 */
	virtual void NotifyAddTime(const float& NewTime) = 0;

	/** This should reset all data */
	virtual void Clear() = 0;

	/** @returns a FNTimelineEventDelegate ref which is broadcast when an event expires. */
	virtual FNEventDelegate& OnStart() = 0;
};
