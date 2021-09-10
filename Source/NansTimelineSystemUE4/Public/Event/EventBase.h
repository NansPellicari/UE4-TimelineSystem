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

#include "EventBase.generated.h"

/**
 * This is only a view object used to retrieve events from blueprint.
 */
UCLASS(Blueprintable, meta=(ShowWorldContextPin))
class NANSTIMELINESYSTEMUE4_API UNEventBase : public UObject, public INEvent
{
	GENERATED_BODY()
public:
	UNEventBase() {}
	void Init(const TSharedPtr<INEvent>& InEvent, const float& InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

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

	/**
	 * @param InLocalTime - the time (in seconds) from the timeline start.
	 *     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	 *     @see UNTimelineManagerDecorator::Serialize()
	 * @param InWorld - the world of the timeline that trigger this event
	 * @param InPlayer - The current player.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnInit(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	/**
	* @param InLocalTime - the time (in seconds) from the timeline start.
	*     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	*     @see UNTimelineManagerDecorator::Serialize()
	* @param InWorld - the world of the timeline that trigger this event
	* @param InPlayer - The current player.
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnStart(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	/**
	* @param InLocalTime - the time (in seconds) from the timeline start.
	*     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	*     @see UNTimelineManagerDecorator::Serialize()
	* @param InWorld - the world of the timeline that trigger this event
	* @param InPlayer - The current player.
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnBeforeAttached(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	/**
	* @param InLocalTime - the time (in seconds) from the timeline start.
	*     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	*     @see UNTimelineManagerDecorator::Serialize()
	* @param InWorld - the world of the timeline that trigger this event
	* @param InPlayer - The current player.
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnAfterAttached(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	/**
	* @param InLocalTime - the time (in seconds) from the timeline start.
	*     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	*     @see UNTimelineManagerDecorator::Serialize()
	* @param InWorld - the world of the timeline that trigger this event
	* @param InPlayer - The current player.
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnExpired(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	/**
	* @param InLocalTime - the time (in seconds) from the timeline start.
	*     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	*     @see UNTimelineManagerDecorator::Serialize()
	* @param InWorld - the world of the timeline that trigger this event
	* @param InPlayer - The current player.
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnTick(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	/**
	* @param InLocalTime - the time (in seconds) from the timeline start.
	*     /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events.
	*     @see UNTimelineManagerDecorator::Serialize()
	* @param InWorld - the world of the timeline that trigger this event
	* @param InPlayer - The current player.
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnCleared(float InLocalTime, UWorld* InWorld, APlayerController* InPlayer);

	virtual void BeginDestroy() override;
	TSharedPtr<INEvent> GetEvent();

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "NansTimeline|Event|Debug")
	FString GetDebugTooltipText() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "NansTimeline|Event|Debug")
	FColor GetDebugColor() const;
#endif

private:
	/**
	 * The actual decorated object.
	 * It is passed in the #Init() function
	 */
	TSharedPtr<INEvent> Event;
};

/**
 * A UNEventBaseBlueprint is essentially a specialized Blueprint whose graphs control an UNEventBase.
 * The UNEventBase factory should pick this for you automatically
 */
UCLASS(BlueprintType)
class NANSTIMELINESYSTEMUE4_API UNEventBaseBlueprint : public UBlueprint
{
	GENERATED_BODY()
public:
#if WITH_EDITOR

	// UBlueprint interface
	inline virtual bool SupportedByDefaultBlueprintFactory() const override;
	// End of UBlueprint interface

	/** Returns the most base gameplay ability blueprint for a given blueprint (if it is inherited from another ability blueprint, returning null if only native / non-ability BP classes are it's parent) */
	static UNEventBaseBlueprint* FindRootEventBlueprint(UNEventBaseBlueprint* DerivedBlueprint);

#endif
};
