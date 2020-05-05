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

/**
 * TODO Add Serialisation (FArchive) + Save user stats
 */
UCLASS(Abstract)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerBase : public UObject, public NTimelineManagerAbstract
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	float Counter = 0;
#if WITH_EDITOR
	UPROPERTY(BlueprintReadWrite)
	bool bDebug = false;
#endif

	UFUNCTION(BlueprintCallable)
	float GetTimelineTime();
	UFUNCTION(BlueprintCallable)
	virtual void Pause() override;
	UFUNCTION(BlueprintCallable)
	virtual void Play() override;
	UFUNCTION(BlueprintCallable)
	virtual void Stop() override;

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
