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

#include "Misc/NansAssertionMacros.h"
#include "TimelineManager.h"

#include "TimelineManagerDecorator.generated.h"

class UNEventBase;

FString EnumToString(const ENTimelineEvent& Value);

/**
 * This class is a factory to managed properly UNTimelineManagerDecorator instantiation.
 */
namespace FNTimelineManagerDecoratorFactory
{
	/**
	 * Method to create a derived UNTimelineManagerDecorator.
	 *
	 * @param Outer - The outer of the new object.
	 * @param TickInterval - The interval between tick in sec
	 * @param InLabel - The name of this new Timeline
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(
		UObject* Outer, const float& TickInterval = 1.f, const FName& InLabel = NAME_None,
		const EObjectFlags& Flags = RF_NoFlags)
	{
		T* Obj = NewObject<T>(Outer, NAME_None, Flags);

		mycheckf(
			Cast<class UNTimelineManagerDecorator>(Obj) != nullptr,
			TEXT("Your TimelineManager class should dervived from UNTimelineManagerDecorator!")
		);
		Obj->Init(TickInterval, InLabel);
		return Obj;
	}

	/**
	 * This method is a factory method to create a derived UNTimelineManagerDecorator with a specific UClass.
	 *
	 * @param Outer - The outer of the new object.
	 * @param Class - The specific class we want our object will be.
	 * @param TickInterval - The interval between tick in sec
	 * @param InLabel - The name of this new Timeline
	 * @param Flags - The EObjectFlags for NewObject().
	 */
	template <typename T>
	static T* CreateObject(UObject* Outer,
		const UClass* Class,
		const float& TickInterval = 1.f,
		const FName& InLabel = NAME_None,
		const EObjectFlags& Flags = EObjectFlags::RF_NoFlags)
	{
		T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
		mycheckf(
			Cast<class UNTimelineManagerDecorator>(Obj) != nullptr,
			TEXT("Your TimelineManager class %s should dervived from UNTimelineManagerDecorator!"),
			*Class->GetFullName()
		);
		Obj->Init(TickInterval, InLabel);
		return Obj;
	}
};

/**
 * This is the abstract decorator that every Timeline manager should override.
 * It brings all core functionalities for blueprint or UE4 c++ paradigm.
 *
 * As the close relation between NTimelineManager and NTimeline classes (core lib),
 * This class is coupled with UNTimelineDecorator.
 * @see UNTimelineDecorator
 *
 * To ease blueprint usages, most of the UNTimelineDecorator public functionalities
 * are accessible here. This class works as a pass-through too for UNTimelineDecorator.
 *
 * @see AddEvent(), CreateNewEvent(), CreateAndAddNewEvent()
 */
UCLASS(Abstract, ConversionRoot, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerDecorator : public UObject, public FNTimelineManager
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "NansTimeline|Manager")
	bool bDebug = false;

	/** The interval retrieved from the timeline. */
	UPROPERTY(EditInstanceOnly, Category= "NansTimeline|Manager")
	float TickInterval = 1.f;

	// BEGIN NTimelineManager overrides
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Pause() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Play() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void Stop() override;

	void OnEventChangedDelegate(TSharedPtr<INEvent> Event, const ENTimelineEvent& EventName,
		const float& LocalTime, const int32& Index);
	/**
	 * The embedded timeline is created as subobject in the ctor.
	 * So this just gives the Label to the timeline.
	 * @see UNTimelineManagerDecorator()
	 *
	 * @param InTickInterval - Interval time between tick in sec
	 * @param InLabel - Name of the Timeline.
	 */
	virtual void Init(const float& InTickInterval = 1.f, const FName& InLabel = NAME_None) override;
	// END NTimelineManager overrides

	// BEGIN UObject overrides
	/**
	 * It's the starting link of serialization chain for all embedded decorators.
	 * This calls UNTimelineDecorator::Serialize().
	 *
	 * @param Ar - the FArchive used for serialization as usual.
	 */
	virtual void Serialize(FArchive& Ar) override;

	/** This calls FNTimelineManager::Clear(). */
	virtual void BeginDestroy() override;
	// END UObject overrides

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	TArray<UNEventBase*> GetEvents() const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	TArray<UNEventBase*> GetExpiredEvents() const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	UNEventBase* GetEvent(const FString& InUID) const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	float GetCurrentTime() const;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	FName GetLabel() const;

	/** A pass-through for the embedded FNTimeline::SetLabel() */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	void SetLabel(const FName& Name);

	UFUNCTION(
		BlueprintCallable, BlueprintImplementableEvent, Category = "NansTimeline|Event",
		meta = (DisplayName = "On Event Changed")
	)
	void OnBPEventChanged(const UNEventBase* StartedEvent, const float& EventTime);

	// @formatter:off
	/**
	 * Attaches the event to the timeline stream
	 * @copydoc UNTimelineManagerDecorator::CreateNewEvent()
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create and add new Event for the NansTimeline", Keywords = "Event create add"), Category = "NansTimeline|Manager")
	UNEventBase* CreateAndAddNewEvent(FName InName, float InDuration = 0, float InDelay = 0, TSubclassOf<UNEventBase> InClass = nullptr);
	// @formatter:on

	/** Remove all EventBases and ExpiredEventBases */
	virtual void Clear() override;
	
protected:
	/**
	 * Protected ctor to force instantiation with CreateObject() methods (factory methods).
	 * It instantiates the embedded timeline with CreateDefaultSubobject().
	 */
	UNTimelineManagerDecorator();
	
	UPROPERTY(BlueprintReadOnly, Category= "NansTimeline|Manager")
	FDateTime StartedAt = -1.f;

	UPROPERTY(SkipSerialization)
	TMap<FString, UNEventBase*> EventBases;
	
	UPROPERTY(SkipSerialization)
	TMap<FString, UNEventBase*> ExpiredEventBases;
};
