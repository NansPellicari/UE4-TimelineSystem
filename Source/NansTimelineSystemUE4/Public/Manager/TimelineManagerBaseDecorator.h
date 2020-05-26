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
#include "TimelineDecorator.h"

#include "TimelineManagerBaseDecorator.generated.h"

class NTimelineEventDecorator;

/**
 * This is the abstract decorator that every Timeline manager shoulds override.
 * It brings all core functionnalities for blueprint or c++.
 *
 * As the close relation between NTimelineManagerBase and NTimeline classes (core lib),
 * This class is coupled with UNTimelineDecorator.
 * @see UNTimelineDecorator
 *
 * To ease blueprint usages, most of the UNTimelineDecorator public functionnalities
 * are accessible here. This class works as a pass-through too for UNTimelineDecorator.
 *
 * @see AddEvent(), CreateNewEvent(), CreateAndAddNewEvent()
 */
UCLASS(Abstract, ConversionRoot, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerBaseDecorator : public UObject, public NTimelineManagerBase
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	UPROPERTY(BlueprintReadWrite, Category = "NansTimeline|Manager")
	bool bDebug = false;
#endif

	// BEGIN NTimelineManagerBase overrides
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Pause() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Play() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Stop() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void SetTickInterval(float _TickInterval) override;

	/**
	 * The embeded timeline is created as subobject in the ctor.
	 * So this just gives the Label to the timeline.
	 * @see UNTimelineManagerBaseDecorator()
	 *
	 * @param _TickInterval - Interval time between tick in sec
	 * @param _Label - Name of the Timeline.
	 */
	virtual void Init(float _TickInterval = 1.f, FName _Label = NAME_None) override;

	/** It is called by the parent NTimelineManagerBase on dtor */
	virtual void Clear() override;
	// END NTimelineManagerBase overrides

	// BEGIN UObject overrides
	/**
	 * It's the starting link of serialization chain for all embeded decorators.
	 * This calls UNTimelineDecorator::Serialize().
	 *
	 * @param Ar - the FArchive used for serialization as usual.
	 */
	virtual void Serialize(FArchive& Ar) override;

	/** This call the UNTimelineDecorator::BeginDestroy() too. */
	virtual void BeginDestroy() override;
	// END UObject overrides

	/**
	 * Get the events list.
	 * TODO should be great to have a type filter possibility with a TSubclassOf<UNTimelineEventDecorator> parameter
	 */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual const TArray<FNEventRecord> GetEvents() const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	float GetCurrentTime() const;

	/** A pass-through for the embeded UNTimelineDecorator::GetLabel() */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	FName GetLabel() const;

	/**
	 * This method is a factory method to create a derived UNTimelineManagerBaseDecorator.
	 *
	 * @param Outer - The outer of the new object.
	 * @param TickInterval - The interval between tick in sec
	 * @param _Label - The name of this new Timeline
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(
		UObject* Outer, float TickInterval = 1.f, FName _Label = NAME_None, EObjectFlags Flags = EObjectFlags::RF_NoFlags);

	/**
	 * This method is a factory method to create a derived UNTimelineManagerBaseDecorator with a specific UClass.
	 *
	 * @param Outer - The outer of the new object.
	 * @param Class - The specific class we want our object will be.
	 * @param TickInterval - The interval between tick in sec
	 * @param _Label - The name of this new Timeline
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(UObject* Outer,
		const UClass* Class,
		float TickInterval = 1.f,
		FName _Label = NAME_None,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags);

	/**
	 * Adds an event to the timeline object,
	 * it works as a pass-through for UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)
	 *
	 * @param Event - An Event object you want to saved to the associated timeline.
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add an Event to the NansTimeline", Keywords = "Event add"), Category = "NansTimeline|Manager")
	virtual void AddEvent(UNTimelineEventDecorator* Event);
	// clang-format on

	/**
	 * A pass-through for UNTimelineDecorator::CreateNewEvent():
	 * @copydoc UNTimelineDecorator::CreateNewEvent()
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create a New Event for the NansTimeline", Keywords = "Event create"), Category = "NansTimeline|Manager")
	UNTimelineEventDecorator* CreateNewEvent(TSubclassOf<UNTimelineEventDecorator> Class, FName Name, float Duration = 0, float Delay = 0);
	// clang-format on

	/**
	 * Attaches the event to the timeline stream +
	 * @copydoc UNTimelineManagerBaseDecorator::CreateNewEvent()
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create and add new Event for the NansTimeline", Keywords = "Event create add"), Category = "NansTimeline|Manager")
	UNTimelineEventDecorator* CreateAndAddNewEvent(TSubclassOf<UNTimelineEventDecorator> Class, FName Name, float Duration = 0, float Delay = 0);
	// clang-format on

protected:
	/** the timeline associated to this manager. */
	UPROPERTY(SkipSerialization)
	UNTimelineDecorator* MyTimeline;

	/**
	 * Protected ctor to force instanciation with CreateObject() methods (factory methods).
	 *
	 * It instanciates the embeded timeline with CreateDefaultSubobject().
	 */
	UNTimelineManagerBaseDecorator();

private:
};
