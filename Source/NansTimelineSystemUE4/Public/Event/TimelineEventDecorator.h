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

#include "TimelineEventDecorator.generated.h"

/**
 * Base abstract class to create NTimelineEventBase decorators (Blueprint or c++).
 *
 * For a simple usage with blueprint:
 * you can derived blueprint base on this.
 * This way the NTimelineEventBase instance should only manage timeline behavior.
 *
 * For a more complex usage in c++:
 * You should derive this and NTimelineEventBase too to fit on your needs.
 * - This class should only manage specifics behaviors related to the engine
 * (serialization, blueprint's specifics functionnalities, etc...)
 * - NTimelineEventBase's derivation: all your core functionnalities
 */
UCLASS(Abstract, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineEventDecorator : public UObject, public NTimelineEventBase
{
	friend class UNTimelineManagerBaseDecorator;

	GENERATED_BODY()
public:
	template <typename T>
	static T* CreateObject(UObject* Outer,
		const TSubclassOf<UNTimelineEventDecorator> Class,
		FName Name = NAME_None,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	template <typename T>
	static T* CreateObjectFromEvent(UObject* Outer,
		const TSharedPtr<NTimelineEventBase> Object,
		const TSubclassOf<UNTimelineEventDecorator> Class,
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
	virtual void Serialize(FArchive& Ar) override;
	// END UObject overrides

	void SetDelay(float _Delay);
	void SetDuration(float _Duration);

	/**
	 * This is where the Core object is instanciated.
	 * You should override this to instanciate your derived core object.
	 */
	virtual void Init(FName _Label);

	/**
	 * This is used by other decorators which need to pass the core object to their own.
	 * @see UNTimelineDecorator::Attached()
	 */
	TSharedPtr<NTimelineEventBase> GetEvent();

protected:
	/**
	 * The actual decorator is for this object.
	 * It shoulds be instanciate on a ctor or a dedicated init function
	 * */
	TSharedPtr<NTimelineEventBase> Event;

	/** Default ctor for the engine */
	UNTimelineEventDecorator() {}
};
