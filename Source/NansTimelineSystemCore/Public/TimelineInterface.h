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

enum class ENTimelineEvent : uint8
{
	/**
	 * This event should be triggered right before an event is attached to a timeline.
	 * This way it can offer the opportunity to avoid an event to be attached in a dedicated logic.
	 */
	BeforeAttached,
	
	/**
	 * This event should be triggered right after an event is attached to a timeline.
	 * This way it can offer the opportunity to create some stats or else...
	 */
	AfterAttached,
	
	/** This event should be triggered when an event expired. */
	Expired,

	/**  */
	Start,
};

DECLARE_MULTICAST_DELEGATE_FourParams(
	FNTimelineEventDelegate,
	TSharedPtr<INEventInterface> /** Event */,
	const ENTimelineEvent& /** EventName */,
	const float& /** ExpiredTime */,
	const int32& /** Index */
);

/**
 * Its goal is to saved events and place them in time.
 * It works as a Time & Event container.
 * The NTimelineManager class is dedicated to handle it.
 *
 * @see ./TimelineManager.h
 */
class NANSTIMELINESYSTEMCORE_API INTimelineInterface
{
public:
	virtual ~INTimelineInterface() = default;

	/** Attached an event to this timeline */
	virtual bool Attached(const TSharedPtr<INEventInterface>& Event) = 0;

	/** Attached a collection of events to this timeline */
	virtual void Attached(const TArray<TSharedPtr<INEventInterface>>& EventsCollection) = 0;

	/**
	 * Defined the tick interval for this timeline
	 *
	 * @param InTickInterval - Time in secs
	 */
	virtual void SetTickInterval(const float& InTickInterval) = 0;

	/**
	 * Should be used only for serialization because it is internnaly computed with NotifyTick()
	 *
	 * @param InCurrentTime - Time in secs
	 */
	virtual void SetCurrentTime(const float& InCurrentTime) = 0;

	/** Retrieve the current time since this timeline exists and play */
	virtual float GetCurrentTime() const = 0;

	/**
	 * Give a name to this timeline
	 *
	 * @param InLabel - The name
	 */
	virtual void SetLabel(const FName& InLabel) = 0;

	/** Return the actual name */
	virtual FName GetLabel() const = 0;

	/** Reset default data */
	virtual void Clear() = 0;

	/** This manages to notify every events saved in this timeline with the new time added. */
	virtual void NotifyTick() = 0;

	/** @returns a FNTimelineEventDelegate ref which is broadcast when an event changes. */
	virtual FNTimelineEventDelegate& OnEventChanged() = 0;

	/** @returns Get the list of all events saved in this timeline */
	virtual TArray<TSharedPtr<INEventInterface>> GetEvents() const = 0;

	/**
	 * Get an event by its UID
	 * @returns the event found or invalid TSharedPtr
	 */
	virtual TSharedPtr<INEventInterface> GetEvent(const FString& InUID) const = 0;

	/**
	 * Offer the opportunities to save data in a binary object.
	 * @param Ar - Archive where we need to save or load data.
	 */
	virtual void Archive(FArchive& Ar) = 0;
};
