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
 * @see NEventInterface
 */
class NANSTIMELINESYSTEMCORE_API NEvent : public NEventInterface
{
public:
	/** Default ctor */
	NEvent();

	/** Ctor to gives directly a name for this event and an Id (optionnal). */
	NEvent(FName _Label, FString _UId = FString(""));

	/** Default dtor */
	virtual ~NEvent(){};

	FNEventDelegate EventStart;
	/**
	 * @copydoc NEventInterface::IsExpired()
	 * It is computed with Duration and LocalTime
	 */
	virtual bool IsExpired() const override;
	virtual const float GetLocalTime() const override;
	virtual const float GetStartedAt() const override;
	virtual float GetDuration() const override;
	virtual void Start(float StartTime) override;
	virtual void Stop() override;
	virtual float GetDelay() const override;
	virtual const FString GetUID() const override;
	virtual void SetUID(FString _UId) override;
	virtual const FName GetEventLabel() const override;
	virtual void SetLocalTime(float _LocalTime) override;
	virtual void SetDuration(float _Duration) override;
	virtual void SetDelay(float _Delay) override;
	virtual void SetEventLabel(FName _EventLabel) override;
	virtual void NotifyAddTime(float NewTime) override;
	virtual void Clear() override;
	virtual FNEventDelegate& OnStart() override;

protected:
	FName Label = NAME_None;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
	FString UId;
	bool bActivated = false;
};
