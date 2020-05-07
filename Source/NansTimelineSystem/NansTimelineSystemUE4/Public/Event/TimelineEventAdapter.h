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
#include "NansTimelineSystemCore/Public/TimelineEventBase.h"

#include "TimelineEventAdapter.generated.h"

/**
 * This class should be used only as a template to create other adapters.
 * You should derive NTimelineEventBase to fit on your needs and this too.
 */
UCLASS(Abstract, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineEventAdapter : public UObject, public NTimelineEventBase
{
	friend class UNTimelineManagerBase;

	GENERATED_BODY()
public:
	UNTimelineEventAdapter() {}

	template <typename T>
	static T* CreateObject(UObject* Outer,
		const TSubclassOf<UNTimelineEventAdapter> Class,
		FName Name = NAME_None,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	template <typename T>
	static T* CreateObjectFromEvent(UObject* Outer,
		const TSharedPtr<NTimelineEventBase> Object,
		const TSubclassOf<UNTimelineEventAdapter> Class,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags);

	// BEGIN NTimelineEventBase overrides
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual bool IsExpired() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const float GetLocalTime() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const float GetStartedAt() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDuration() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void Start(float StartTime) override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void NotifyAddTime(float NewTime) override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDelay() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const FName GetEventLabel() const override;
	// END NTimelineEventBase overrides

	// BEGIN UObject overrides
	virtual void BeginDestroy() override;
	// END UObject overrides

	void SetDelay(float _Delay);

protected:
	/**
	 * Is protected so it is destinated to be used by its friend class "UNTimelineManagerBase" only
	 * @see ./Manager/TimelineManagerBase.h
	 */
	TSharedPtr<NTimelineEventBase> GetEvent();

	/** The actual adapter is for this object. It shoulds be instanciate on a ctor or a dedicated init function */
	TSharedPtr<NTimelineEventBase> Event;
};
