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
class NANSTIMELINESYSTEMCORE_API FNEvent : public INEventInterface
{
public:
	/** Default ctor */
	FNEvent();

	/** Ctor to gives directly a name for this event and an Id (optional). */
	FNEvent(const FName& InLabel, const FString& InUId = FString(""));
	/** Ctor to init an Event from saved data. */
	FNEvent(const FNEventSave& Record);

	/** Default dtor */
	virtual ~FNEvent() override = default;

	// ~ Begin INEventInterface overrides
	virtual bool IsExpired() const override;
	virtual float GetLocalTime() const override;
	virtual float GetAttachedTime() const override;
	virtual void SetAttachedTime(const float& InLocalTime) override;
	virtual void SetAttachable(const bool& bInIsAttachable) override;
	virtual bool IsAttachable() const override;
	virtual float GetStartedAt() const override;
	virtual float GetDuration() const override;
	virtual void Start(const float& StartTime) override;
	virtual void Stop() override;
	virtual float GetDelay() const override;
	virtual FString GetUID() const override;
	virtual float GetExpiredTime() const override;
	virtual void SetUID(const FString& InUId) override;
	virtual FName GetEventLabel() const override;
	virtual void SetLocalTime(const float& InLocalTime) override;
	virtual void SetDuration(const float& InDuration) override;
	virtual void SetDelay(const float& InDelay) override;
	virtual void SetEventLabel(const FName& InEventLabel) override;
	virtual void SetExpiredTime(const float& InLocalTime) override;
	virtual void NotifyAddTime(const float& NewTime) override;
	virtual void Clear() override;
	// ~ End INEventInterface overrides

protected:
	FName Label = NAME_None;
	float AttachedTime = 0.f;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float ExpiredTime = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
	FString UId;
	bool bActivated = false;
	bool bIsAttachable = true;
};
