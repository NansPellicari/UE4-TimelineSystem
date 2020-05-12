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
 * An absctract class to manage events which can be attached to a timeline.
 */
class NANSTIMELINESYSTEMCORE_API NTimelineEventBase
{
public:
	NTimelineEventBase() {}
	NTimelineEventBase(FName _Label) : Label(_Label) {}
	virtual bool IsExpired() const;

	/** Should be great to have a doc */
	virtual const float GetLocalTime() const;
	virtual const float GetStartedAt() const;
	virtual float GetDuration() const;
	virtual void Start(float StartTime);
	virtual void NotifyAddTime(float NewTime);
	virtual float GetDelay() const;
	virtual const FName GetEventLabel() const;
	virtual void Clear();

	FName Label = NAME_None;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
};
