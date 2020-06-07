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

/**
 * An abstract class to manage events which can be attached to a timeline.
 */
class NANSTIMELINESYSTEMCORE_API NEvent : public NEventInterface
{
public:
	/** Default ctor */
	NEvent();

	/** Ctor to gives directly a name for this event and Id (optionnal). */
	NEvent(FName _Label, FString _UId = FString(""));

	virtual ~NEvent(){};

	/** It computes with Duration and LocalTime */
	virtual bool IsExpired() const override;

	/** Getter for LocalTime */
	virtual const float GetLocalTime() const override;

	/** Getter for StartedAt */
	virtual const float GetStartedAt() const override;

	/** Getter for Duration */
	virtual float GetDuration() const override;

	/** A setter for StartedAt */
	virtual void Start(float StartTime) override;

	/** Increments LocalTime */
	virtual float GetDelay() const override;
	virtual const FString GetUID() const override;
	virtual void SetUID(FString _UId) override;

	/** Getter for Label */
	virtual const FName GetEventLabel() const override;

	virtual void SetLocalTime(float _LocalTime) override;
	virtual void SetStartedAt(float _StartedAt) override;
	virtual void SetDuration(float _Duration) override;
	virtual void SetDelay(float _Delay) override;
	virtual void SetEventLabel(FName _EventLabel) override;
	/**
	 * Increments LocalTime
	 * @param NewTime - in Millisecs
	 */
	virtual void NotifyAddTime(float NewTime) override;

	/** Reset all default data */
	virtual void Clear() override;

protected:
	FName Label = NAME_None;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
	FString UId;
};
