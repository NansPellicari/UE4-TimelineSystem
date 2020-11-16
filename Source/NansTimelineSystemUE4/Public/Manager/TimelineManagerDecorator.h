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
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineManager.h"

#include "TimelineManagerDecorator.generated.h"

struct FNEventRecord;
class UNEventView;

/**
 * This class is a factory to managed properly UNTimelineManagerDecorator instanciation.
 */
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerDecoratorFactory
{
public:
	/**
	 * Method to create a derived UNTimelineManagerDecorator.
	 *
	 * @param Outer - The outer of the new object.
	 * @param TickInterval - The interval between tick in sec
	 * @param _Label - The name of this new Timeline
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(
		UObject* Outer, float TickInterval = 1.f, FName _Label = NAME_None,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags)
	{
		T* Obj = NewObject<T>(Outer, NAME_None, Flags);

		mycheckf(
			Cast<UNTimelineManagerDecorator>(Obj) != nullptr,
			TEXT("Your TimelineManager class should dervived from UNTimelineManagerDecorator!")
		);
		Obj->Init(TickInterval, _Label);
		return Obj;
	}

	/**
	 * This method is a factory method to create a derived UNTimelineManagerDecorator with a specific UClass.
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
		EObjectFlags Flags = EObjectFlags::RF_NoFlags)
	{
		T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
		mycheckf(
			Cast<UNTimelineManagerDecorator>(Obj) != nullptr,
			TEXT("Your TimelineManager class %s should dervived from UNTimelineManagerDecorator!"),
			*Class->GetFullName()
		);
		Obj->Init(TickInterval, _Label);
		return Obj;
	}
};

/**
 * This is the abstract decorator that every Timeline manager shoulds override.
 * It brings all core functionnalities for blueprint or UE4 c++ paradigm.
 *
 * As the close relation between NTimelineManager and NTimeline classes (core lib),
 * This class is coupled with UNTimelineDecorator.
 * @see UNTimelineDecorator
 *
 * To ease blueprint usages, most of the UNTimelineDecorator public functionnalities
 * are accessible here. This class works as a pass-through too for UNTimelineDecorator.
 *
 * @see AddEvent(), CreateNewEvent(), CreateAndAddNewEvent()
 */
UCLASS(Abstract, ConversionRoot, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerDecorator : public UObject, public NTimelineManager
{
	GENERATED_BODY()
public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadWrite, Category = "NansTimeline|Manager")
	bool bDebug = false;
#endif	  // WITH_EDITORONLY_DATA

	// BEGIN NTimelineManager overrides
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
	 * @see UNTimelineManagerDecorator()
	 *
	 * @param _TickInterval - Interval time between tick in sec
	 * @param _Label - Name of the Timeline.
	 */
	virtual void Init(float _TickInterval = 1.f, FName _Label = NAME_None) override;
	// END NTimelineManager overrides

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

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	const TArray<UNEventView*> GetEventViews() const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	UNEventView* GetEventView(FString _UID);

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	float GetCurrentTime() const;

	/** A pass-through for the embeded UNTimelineDecorator::GetLabel() */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	FName GetLabel() const;

	// @formatter:off
	/**
	 * Attaches the event to the timeline stream
	 * @copydoc UNTimelineManagerDecorator::CreateNewEvent()
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create and add new Event for the NansTimeline", Keywords = "Event create add"), Category = "NansTimeline|Manager")
	void CreateAndAddNewEvent(FName Name, float Duration = 0, float Delay = 0);
	// @formatter:on

protected:

	/**
	 * Protected ctor to force instanciation with CreateObject() methods (factory methods).
	 *
	 * It instanciates the embeded timeline with CreateDefaultSubobject().
	 */
	UNTimelineManagerDecorator();

private:
};
