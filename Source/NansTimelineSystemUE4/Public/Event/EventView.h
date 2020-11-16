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
#include "NansTimelineSystemCore/Public/EventInterface.h"

#include "EventView.generated.h"

/**
 * This is only a view object used to retrieve events from blueprint.
 * This is a readonly object.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNEventView : public UObject, public NEventInterface
{
	GENERATED_BODY()
public:
	UNEventView() {}
	void Init(TSharedPtr<NEventInterface> _Event);

	// BEGIN NEventInterface overrides
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual bool IsExpired() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const float GetLocalTime() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const float GetStartedAt() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDuration() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDelay() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const FName GetEventLabel() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void SetEventLabel(FName _EventLabel) override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const FString GetUID() const override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnStartEvent(const UNEventView* StartedEvent, const float& StartTime);

	// View object = no alteration 
	virtual void Start(float StartTime) override {}
	virtual void Stop() override {}
	virtual void NotifyAddTime(float NewTime) override {}
	virtual FNEventDelegate& OnStart() override;
	virtual void SetUID(FString _UId) override {}
	virtual void SetLocalTime(float _LocalTime) override {}
	virtual void SetDuration(float _Duration) override {}
	virtual void SetDelay(float _Delay) override {}
	virtual void Clear() override {}
	virtual void PreDelete() override {}
	// END NEventInterface overrides

	virtual void BeginDestroy() override;

	TSharedPtr<NEventInterface> GetEvent();

private:
	/**
	 * The actual decorator is for this object.
	 * It should be instantiate on a ctor or a dedicated init function
	 */
	TSharedPtr<NEventInterface> Event;

	void WhenOnStart(NEventInterface*, const float& StartTime);
};
