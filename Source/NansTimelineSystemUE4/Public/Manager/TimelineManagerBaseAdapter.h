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
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineManagerAbstract.h"
#include "TimelineAdapter.h"

#include "TimelineManagerBaseAdapter.generated.h"

class NTimelineEventAdapter;

/**
 * TODO Add Save user stats
 */
UCLASS(Abstract, ConversionRoot, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerBaseAdapter : public UObject, public NTimelineManagerAbstract
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	UPROPERTY(BlueprintReadWrite, Category = "NansTimeline|Manager")
	bool bDebug = false;
#endif

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	float GetTimelineTime();

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Pause() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Play() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Stop() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	FName GetLabel() const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual const TArray<FNEventRecord> GetEvents();

	virtual void Init(FName _Label = NAME_None) override;

	virtual void Serialize(FArchive& Ar) override;
	virtual void BeginDestroy() override;

	template <typename T>
	static T* CreateObject(UObject* Outer, FName _Label = NAME_None, EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	template <typename T>
	static T* CreateObject(
		UObject* Outer, const UClass* Class, FName _Label = NAME_None, EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	/** It is called by the parent NTimelineManagerAbstract on dtor */
	virtual void Clear() override;

	/**
	 * Add an event to the timeline object
	 * @param Event - An object you want to saved to the associated timeline.
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add an Event to the timeline", Keywords = "Event add"), Category = "NansTimeline|Manager")
	virtual void AddEvent(UNTimelineEventAdapter* Event);
	// clang-format on

	/**
	 * Create a new Event and use the actual timeline as the outer for this new object.
	 *
	 * @param Class - The derived class of your choice
	 * @param Name - The label of the event, can be usefull for user stats & feedback
	 * @param Duration - The time this event is active, 0 to almost INFINI (0 means undeterminated time)
	 * @param Delay - The time before this event start being active, 0 to almost INFINI (0 means "right now")
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create a New Event for the timeline", Keywords = "Event create"), Category = "NansTimeline|Manager")
	UNTimelineEventAdapter* CreateNewEvent(TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration = 0, float Delay = 0);
	// clang-format on

	/**
	 * Create a new Event and add it to the actual embeded timeline
	 *
	 * @param Class - The derived class of your choice
	 * @param Name - The label of the event, can be usefull for user stats & feedback
	 * @param Duration - The time this event is active, 0 to almost INFINI (0 means undeterminated time)
	 * @param Delay - The time before this event start being active, 0 to almost INFINI (0 means "right now")
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create and add new Event for the timeline", Keywords = "Event create add"), Category = "NansTimeline|Manager")
	UNTimelineEventAdapter* CreateAndAddNewEvent(TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration = 0, float Delay = 0);
	// clang-format on

protected:
	UPROPERTY(SkipSerialization)
	UNTimelineAdapter* MyTimeline;

	UNTimelineManagerBaseAdapter();

private:
};
