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
#include "NansTimelineSystemCore/Public/TimelineManagerBase.h"
#include "TimelineAdapter.h"

#include "TimelineManagerBaseAdapter.generated.h"

class NTimelineEventAdapter;

/**
 * This is the abstract adapter that every Timeline manager shoulds override.
 * It brings all core functionnalities for blueprint or c++.
 *
 * As the close relation between NTimelineManagerBase and NTimeline classes (core lib),
 * This class is coupled with UNTimelineAdapter.
 * @see UNTimelineAdapter
 *
 * To ease blueprint usages, most of the UNTimelineAdapter public functionnalities
 * are accessible here. This class works as a pass-through too for UNTimelineAdapter.
 *
 * @see AddEvent(), CreateNewEvent(), CreateAndAddNewEvent()
 */
UCLASS(Abstract, ConversionRoot, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerBaseAdapter : public UObject, public NTimelineManagerBase
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	UPROPERTY(BlueprintReadWrite, Category = "NansTimeline|Manager")
	bool bDebug = false;
#endif

	// BEGIN UObject overrides
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	float GetTimelineTime();

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Pause() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Play() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Stop() override;

	/**
	 * The embeded timeline is created as subobject in the ctor.
	 * So this just gives the Label to the timeline.
	 * @see UNTimelineManagerBaseAdapter()
	 *
	 * @param _Label - Name of the Timeline.
	 */
	virtual void Init(FName _Label = NAME_None) override;
	// END NTimeline overrides

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual const TArray<FNEventRecord> GetEvents();

	// BEGIN UObject overrides
	/**
	 * It's the starting link of serialization chain for all embeded adapters.
	 * This calls UNTimelineAdapter::Serialize().
	 *
	 * @param Ar - the FArchive used for serialization as usual.
	 */
	virtual void Serialize(FArchive& Ar) override;

	/** This call the UNTimelineAdapter::BeginDestroy() too. */
	virtual void BeginDestroy() override;
	// END UObject overrides

	/** A pass-through for the embeded UNTimelineAdapter::GetLabel() */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	FName GetLabel() const;

	/**
	 * This method is a factory method to create a derived UNTimelineManagerBaseAdapter.
	 *
	 * @param Outer - The outer of the new object.
	 * @param _Label - The name of this new Object (is the internal name used by NewObject()).
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(UObject* Outer, FName _Label = NAME_None, EObjectFlags Flags = EObjectFlags::RF_NoFlags);

	/**
	 * This method is a factory method to create a derived UNTimelineManagerBaseAdapter with a specific UClass.
	 *
	 * @param Outer - The outer of the new object.
	 * @param Class - The specific class we want our object will be.
	 * @param _Label - The name of this new Object (is the internal name used by NewObject()).
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(
		UObject* Outer, const UClass* Class, FName _Label = NAME_None, EObjectFlags Flags = EObjectFlags::RF_NoFlags);

	/** It is called by the parent NTimelineManagerBase on dtor */
	virtual void Clear() override;

	/**
	 * Adds an event to the timeline object,
	 * it works as a pass-through for UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)
	 *
	 * @param Event - An Event object you want to saved to the associated timeline.
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add an Event to the timeline", Keywords = "Event add"), Category = "NansTimeline|Manager")
	virtual void AddEvent(UNTimelineEventAdapter* Event);
	// clang-format on

	/**
	 * A pass-through for UNTimelineAdapter::CreateNewEvent():
	 * @copydoc UNTimelineAdapter::CreateNewEvent()
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create a New Event for the timeline", Keywords = "Event create"), Category = "NansTimeline|Manager")
	UNTimelineEventAdapter* CreateNewEvent(TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration = 0, float Delay = 0);
	// clang-format on

	/**
	 * Attaches the event to the timeline stream +
	 * @copydoc UNTimelineManagerBaseAdapter::CreateNewEvent()
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create and add new Event for the timeline", Keywords = "Event create add"), Category = "NansTimeline|Manager")
	UNTimelineEventAdapter* CreateAndAddNewEvent(TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration = 0, float Delay = 0);
	// clang-format on

protected:
	/** the timeline associated to this manager. */
	UPROPERTY(SkipSerialization)
	UNTimelineAdapter* MyTimeline;

	/**
	 * Protected ctor to force instanciation with CreateObject() methods (factory methods).
	 *
	 * It instanciates the embeded timeline with CreateDefaultSubobject().
	 */
	UNTimelineManagerBaseAdapter();

private:
};
