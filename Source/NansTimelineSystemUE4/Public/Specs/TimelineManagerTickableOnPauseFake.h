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
#include "Engine/EngineTypes.h"
#include "NansTimelineSystemCore/Public/TimelineManagerBase.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "Specs/TimelineManagerFake.h"
#include "TimerManager.h"

/**
 * This class is used for tests only
 */
class TimelineManagerTickableOnPauseFake : public NTimelineManagerBase, public FTickableGameObject
{
public:
	float Counter = 0;
	float TotalLifeTime = 0;
	float LastTimeTick = 0;
	UWorld* World;

	TimelineManagerTickableOnPauseFake(UWorld* _World)
	{
		World = _World;
	}

	virtual bool IsTickableWhenPaused() const override
	{
		return true;
	}
	virtual void Tick(float DeltaTime)
	{
		TotalLifeTime += DeltaTime;
		if (FMath::IsNearlyEqual(TotalLifeTime - LastTimeTick, GetTickInterval(), 0.001f))
		{
			LastTimeTick = TotalLifeTime;
			TimerTick();
		}
	}

	virtual bool IsTickable() const override
	{
		return State != ENTimelineTimerState::Played ? false : true;
	}

	virtual void onNotifyTimelineTickBefore() override
	{
		Counter++;
		UE_LOG(LogTemp, Display, TEXT("%s - tick %f"), ANSI_TO_TCHAR(__FUNCTION__), Counter);
	}

	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TimelineManagerTickableOnPauseFake, STATGROUP_Tickables);
	}

	virtual UWorld* GetTickableGameObjectWorld() const override
	{
		return World;
	}
};