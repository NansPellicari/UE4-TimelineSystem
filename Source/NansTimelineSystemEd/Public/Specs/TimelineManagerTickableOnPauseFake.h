// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NansTimelineSystemCore/Public/TimelineManager.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "Specs/TimelineManagerFake.h"
#include "TimerManager.h"

/**
 * This class is used for tests only
 */
class FNTimelineManagerTickableOnPauseFake final : public FNTimelineManager, public FTickableGameObject
{
public:
	float Counter = 0;
	float TotalLifeTime = 0;
	float LastTimeTick = 0;
	UWorld* World;

	FNTimelineManagerTickableOnPauseFake(UWorld* _World)
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
		if (FMath::IsNearlyEqual(TotalLifeTime - LastTimeTick, GetTimeline()->GetTickInterval(), 0.001f))
		{
			LastTimeTick = TotalLifeTime;
			TimerTick(DeltaTime);
		}
	}

	virtual bool IsTickable() const override
	{
		return State != ENTimelineTimerState::Played ? false : true;
	}

	virtual void OnNotifyTimelineTickBefore(const float& InDeltaTime) override
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
