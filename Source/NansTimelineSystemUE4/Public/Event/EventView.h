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
#include "Event.h"

#include "EventView.generated.h"

/**
 * This is only a view object used to retrieve events from blueprint.
 * This is a readonly object.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNEventView : public UObject, public INEvent
{
	GENERATED_BODY()
public:
	UNEventView() {}
	void Init(const TSharedPtr<INEvent>& InEvent);

	// BEGIN INEvent overrides
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

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void Stop() override;

	virtual void SetAttachedTime(const float& InLocalTime) override {}
	virtual void SetAttachable(const bool& bInIsAttachable) override {}
	virtual void SetExpiredTime(const float& InLocalTime) override {}
	virtual void SetDuration(const float& InDuration) override {}
	virtual void SetDelay(const float& InDelay) override {}
	virtual void Start(const float& StartTime) override {}
	virtual void AddTime(const float& NewTime) override {}
	virtual void Clear() override {}
	virtual void Archive(FArchive& Ar) override {}
	// END INEvent overrides
	
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnInit();

	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnStart(float InLocalTime = -1.f);

	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnBeforeAttached(float InLocalTime = -1.f);

	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnAfterAttached(float InLocalTime = -1.f);

	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnExpired(float InLocalTime = -1.f);

	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnTick(float InLocalTime = -1.f);

	virtual void BeginDestroy() override;
	TSharedPtr<INEvent> GetEvent();

private:
	/**
	 * The actual decorated object.
	 * It is passed in the #Init() function
	 */
	TSharedPtr<INEvent> Event;
};

/**
 * A UNEventViewBlueprint is essentially a specialized Blueprint whose graphs control an UNEventView.
 * The UNEventView factory should pick this for you automatically
 */
UCLASS(BlueprintType)
class NANSTIMELINESYSTEMUE4_API UNEventViewBlueprint : public UBlueprint
{
	GENERATED_BODY()
public:
#if WITH_EDITOR

	// UBlueprint interface
	inline virtual bool SupportedByDefaultBlueprintFactory() const override;
	// End of UBlueprint interface

	/** Returns the most base gameplay ability blueprint for a given blueprint (if it is inherited from another ability blueprint, returning null if only native / non-ability BP classes are it's parent) */
	static UNEventViewBlueprint* FindRootEventViewBlueprint(UNEventViewBlueprint* DerivedBlueprint);

#endif
};
