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

#include "EventView.generated.h"

/**
 * This is only a view object used to retrieve events from blueprint.
 * This is a readonly object.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNEventView : public UObject, public INEventInterface
{
	GENERATED_BODY()
public:
	UNEventView() {}
	void Init(TSharedPtr<INEventInterface> _Event);

	// BEGIN INEventInterface overrides
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual bool IsExpired() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetLocalTime() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetStartedAt() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDuration() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDelay() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual FName GetEventLabel() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void SetEventLabel(const FName& InEventLabel) override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual FString GetUID() const override;
	
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetAttachedTime() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual bool IsAttachable() const override;

	
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetExpiredTime() const override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnStartEvent(const UNEventView* StartedEvent, const float& StartTime);

	// View object = no alteration 
	virtual void Start(const float& StartTime) override {}
	virtual void Stop() override {}
	virtual void NotifyAddTime(const float& NewTime) override {}
	virtual FNEventDelegate& OnStart() override;
	virtual void SetUID(const FString& InUId) override {}
	virtual void SetLocalTime(const float& InLocalTime) override {}
	virtual void SetDuration(const float& InDuration) override {}
	virtual void SetDelay(const float& InDelay) override {}
	virtual void Clear() override {}
	virtual void SetAttachedTime(const float& InLocalTime) override {}
	virtual void SetExpiredTime(const float& InLocalTime) override {}
	virtual void SetAttachable(const bool& bInIsAttachable) override {};
	// END INEventInterface overrides
	virtual void BeginDestroy() override;

	TSharedPtr<INEventInterface> GetEvent();

private:
	/**
	 * The actual decorator is for this object.
	 * It should be instantiate on a ctor or a dedicated init function
	 */
	TSharedPtr<INEventInterface> Event;

	void WhenOnStart(INEventInterface*, const float& StartTime);
};
