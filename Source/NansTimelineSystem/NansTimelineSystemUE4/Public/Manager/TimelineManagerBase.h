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
#include "NansTimelineSystemCore/Public/TimelineManagerAbstract.h"

#include "TimelineManagerBase.generated.h"

class NTimelineEventAdapter;

/**
 * TODO Add Serialisation (FArchive) + Save user stats
 */
UCLASS(Abstract, ConversionRoot, Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerBase : public UObject, public NTimelineManagerAbstract
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "NansTimeline|Manager")
	float Counter = 0;

	UPROPERTY(BlueprintReadWrite, Category = "NansTimeline|Manager")
	TSubclassOf<UNTimelineEventAdapter> DefaultClassForEvent;

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

	/**
	 * Add an event to the timeline object
	 * @param Event - An object you want to saved to the associated timeline.
	 */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual void AddEvent(UNTimelineEventAdapter* Event);

	UFUNCTION(BlueprintCallable, Category = "NansTimeline|Manager")
	virtual const TArray<UNTimelineEventAdapter*> GetEvents();

	template <typename T>
	static T* CreateObject(UObject* Outer, EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	template <typename T>
	static T* CreateObject(UObject* Outer, const UClass* Class, EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	virtual void Init(){};

	/** It is called by the parent NTimelineManagerAbstract on dtor */
	virtual void Clear() override;
	virtual void BeginDestroy() override;
	virtual void onNotifyTimelineTickBefore() override;

protected:
	UNTimelineManagerBase();

private:
};

