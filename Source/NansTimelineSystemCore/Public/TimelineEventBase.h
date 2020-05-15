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

/**
 * An abstract class to manage events which can be attached to a timeline.
 */
class NANSTIMELINESYSTEMCORE_API NTimelineEventBase
{
public:
	/** Default ctor */
	NTimelineEventBase() {}

	/** Ctor to gives directly a name for this event. */
	NTimelineEventBase(FName _Label) : Label(_Label) {}

	/** It computes with Duration and LocalTime */
	virtual bool IsExpired() const;

	/** Getter for LocalTime */
	virtual const float GetLocalTime() const;

	/** Getter for StartedAt */
	virtual const float GetStartedAt() const;

	/** Getter for Duration */
	virtual float GetDuration() const;

	/** A setter for StartedAt */
	virtual void Start(float StartTime);

	/**
	 * Increments LocalTime
	 * @param NewTime - in Millisecs
	 */
	virtual void NotifyAddTime(float NewTime);

	/** Increments LocalTime */
	virtual float GetDelay() const;

	/** Getter for Label */
	virtual const FName GetEventLabel() const;

	/** Reset all default data */
	virtual void Clear();

	FName Label = NAME_None;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
};
