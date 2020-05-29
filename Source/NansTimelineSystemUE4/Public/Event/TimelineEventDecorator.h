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

namespace UNTimelineEventDecoratorFactory
{
	template <typename T>
	static T* CreateObject(UObject* Outer,
		const TSubclassOf<UNTimelineEventDecorator> Class,
		FName Name = NAME_None,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags)
	{
		static int32 Counter;
		if (Name == NAME_None)
		{
			FString EvtLabel = FString::Format(TEXT("EventDecorator_{0}"), {++Counter});
			Name = FName(*EvtLabel);
		}

		T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
		Obj->Init(Name);
		return Obj;
	}

	template <typename T>
	static T* CreateObjectFromEvent(UObject* Outer,
		const TSharedPtr<NTimelineEventInterface> Object,
		const TSubclassOf<UNTimelineEventDecorator> Class,
		EObjectFlags Flags = EObjectFlags::RF_NoFlags)
	{
		T* Obj = NewObject<T>(Outer, Class, NAME_None, Flags);
		Obj->Event = Object;
		return Obj;
	}

}	 // namespace UNTimelineEventDecoratorFactory

/**
 * Base abstract class to create NTimelineEventInterface decorators (Blueprint or c++).
 *
 * For a simple usage with blueprint:
 * you can derived blueprint base on this.
 * This way the NTimelineEventInterface instance should only manage timeline behavior.
 *
 * For a more complex usage in c++:
 * You should derive this and NTimelineEventInterface too to fit on your needs.
 * - This class should only manage specifics behaviors related to the engine
 * (serialization, blueprint's specifics functionnalities, etc...)
 * - NTimelineEventBase's derivation: all your core functionnalities
 */
UCLASS(Abstract, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineEventDecorator : public UObject, public NTimelineEventInterface
{
	friend class UNTimelineManagerBaseDecorator;

	GENERATED_BODY()
public:
	UNTimelineEventDecorator() {}

	// BEGIN NTimelineEventInterface overrides
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

	virtual const FString GetUID() const override;
	virtual void SetLocalTime(float _LocalTime) override;
	virtual void SetStartedAt(float _StartedAt) override;
	virtual void SetDuration(float _Duration) override;
	virtual void SetDelay(float _Delay) override;
	virtual void SetEventLabel(FName _EventLabel) override;
	virtual void Clear() override;
	// END NTimelineEventInterface overrides

	// BEGIN UObject overrides
	virtual void BeginDestroy() override;
	virtual void Serialize(FArchive& Ar) override;
	// END UObject overrides

	/**
	 * This is where the Core object is instanciated.
	 * You should override this to instanciate your derived core object.
	 */
	virtual void Init(FName _Label);

	/**
	 * This is used by other decorators which need to pass the core object to their own.
	 * @see UNTimelineDecorator::Attached()
	 */
	virtual TSharedPtr<NTimelineEventInterface> GetEvent() const;

protected:
	/**
	 * The actual decorator is for this object.
	 * It shoulds be instanciate on a ctor or a dedicated init function
	 */
	TSharedPtr<NTimelineEventInterface> Event;

private:
	// Use for saving
	FName Label = NAME_None;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
};
