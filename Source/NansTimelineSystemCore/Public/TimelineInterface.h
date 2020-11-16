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

DECLARE_MULTICAST_DELEGATE_ThreeParams(
	FNTimelineEventDelegate,
	TSharedPtr<NEventInterface>,
	const float&,
	const int32&
);

/**
 * Its goal is to saved events and place them in time.
 * It works as a Time & Event container.
 * The NTimelineManager class is dedicated to handle it.
 *
 * @see ./TimelineManager.h
 */
class NANSTIMELINESYSTEMCORE_API NTimelineInterface
{
public:
	/** Attached an event to this timeline */
	virtual bool Attached(TSharedPtr<NEventInterface> Event) = 0;
	/** Attached a collection of events to this timeline */
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) = 0;
	/**
	 * Defined the tick interval for this timeline
	 *
	 * @param _TickInterval - Time in secs
	 */
	virtual void SetTickInterval(float _TickInterval) = 0;
	/**
	 * Should be used only for serialization because it is internnaly computed with NotifyTick()
	 *
	 * @param _CurrentTime - Time in secs
	 */
	virtual void SetCurrentTime(float _CurrentTime) = 0;
	/** Retrieve the current time since this timeline exists and play */
	virtual float GetCurrentTime() const = 0;
	/**
	 * Give a name to this timeline
	 *
	 * @param _Label - The name
	 */
	virtual void SetLabel(FName _Label) = 0;
	/** Return the actual name */
	virtual FName GetLabel() const = 0;
	/** Reset default data */
	virtual void Clear() = 0;
	/** This manages to notify every events saved in this timeline with the new time added. */
	virtual void NotifyTick() = 0;
	/** @returns a FNTimelineEventDelegate ref which is broadcasted when an event expires. */
	virtual FNTimelineEventDelegate& OnEventExpired() = 0;

	virtual TArray<TSharedPtr<NEventInterface>> GetEvents() = 0;
	virtual TSharedPtr<NEventInterface> GetEvent(FString _UID) = 0;

	virtual void PreDelete() = 0;
	virtual void Archive(FArchive& Ar) = 0;
};
