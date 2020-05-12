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
#include "Runtime/Engine/Public/Tickable.h"
#include "TimelineManagerBaseAdapter.h"

#include "RealLifeTimelineManager.generated.h"

UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNRealLifeTimelineManager : public UNTimelineManagerBaseAdapter, public FTickableGameObject
{
	GENERATED_BODY()
public:
	virtual void Pause() override;

	virtual void Play() override;

	virtual void Stop() override;

	virtual void Init(FName _Label = NAME_None) override;

	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}

	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TimelineManagerTickableOnPauseFake, STATGROUP_Tickables);
	}

	virtual UWorld* GetTickableGameObjectWorld() const override;

	virtual void Serialize(FArchive& Ar) override;

	UPROPERTY(BlueprintReadOnly, SaveGame)
	FDateTime CreationTime;

protected:
	float TotalLifeTime = 0;
	FDateTime LastPlayTime;

	float LastTimeTick = 0;

	UNRealLifeTimelineManager();

private:
};
