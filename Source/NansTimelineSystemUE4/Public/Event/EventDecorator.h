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
#include "NansTimelineSystemCore/Public/EventInterface.h"

#include "EventDecorator.generated.h"

/**
 * Factory functions to help creating event decorators.
 */
namespace UNEventDecoratorFactory
{
	/**
	 * This will instanciate a new Event decorator based on class UNEventDecorator.
	 * It uses UNEventDecorator::Init() function too to have a fully initialized object.
	 *
	 * @param Outer - The UObject outer
	 * @param Class - A subclass of UNEventDecorator
	 * @param Name - (optionnal) the name you want this event is called, it gives a generated ones if not provided
	 * @param Flags - Flag for GC management
	 */
	template <typename T>
	static T* CreateObject(UObject* Outer,
		const TSubclassOf<UNEventDecorator> Class,
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

}	 // namespace UNEventDecoratorFactory

/**
 * Base abstract class to create NEventInterface decorators (Blueprint or c++).
 *
 * For a simple usage with blueprint:
 * you can derived blueprint base on this.
 * This way the NEventInterface instance should only manage timeline behavior.
 *
 * For a more complex usage in c++:
 * You should derive this and NEventInterface too to fit on your needs.
 * - This class should only manage specifics behaviors related to the engine
 * (serialization, blueprint's specifics functionnalities, etc...)
 * - NEventInterface's derivation: all your core functionnalities
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNEventDecorator : public UObject, public NEventInterface
{
	friend class UNTimelineManagerDecorator;

	GENERATED_BODY()
public:
	UNEventDecorator() {}

	// BEGIN NEventInterface overrides
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
	virtual void Stop() override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void NotifyAddTime(float NewTime) override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual float GetDelay() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual const FName GetEventLabel() const override;

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Event")
	virtual void SetEventLabel(FName _EventLabel) override;

	virtual const FString GetUID() const override;
	virtual void SetUID(FString _UId) override;
	virtual void SetLocalTime(float _LocalTime) override;
	virtual void SetDuration(float _Duration) override;
	virtual void SetDelay(float _Delay) override;
	virtual void Clear() override;
	virtual FNEventDelegate& OnStart() override;
	// END NEventInterface overrides

	// BEGIN UObject overrides
	virtual void BeginDestroy() override;
	virtual void Serialize(FArchive& Ar) override;
	// END UObject overrides

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "NansTimeline|Event")
	void OnInit();

	/**
	 * This is where the Core object is instanciated.
	 * You should override this to instanciate your derived core object.
	 */
	virtual void Init(FName _Label, FString UId = FString(""));

	/**
	 * This is used by other decorators which need to pass the core object to their own.
	 * @see UNTimelineDecorator::Attached()
	 */
	virtual TSharedPtr<NEventInterface> GetEvent() const;

protected:
	/**
	 * The actual decorator is for this object.
	 * It shoulds be instanciate on a ctor or a dedicated init function
	 */
	TSharedPtr<NEventInterface> Event;

private:
	// Use for saving
	FName Label = NAME_None;
	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
	FString Id = FString("");
};
