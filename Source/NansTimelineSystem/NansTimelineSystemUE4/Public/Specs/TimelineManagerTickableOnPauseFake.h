#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NansTimelineSystemCore/Public/TimelineManagerAbstract.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "Specs/TimelineManagerFake.h"
#include "TimerManager.h"

class TimelineManagerTickableOnPauseFake : public NTimelineManagerAbstract, public FTickableGameObject
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

	virtual bool IsTickableWhenPaused() const
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

	virtual UWorld* GetTickableGameObjectWorld() const
	{
		return World;
	}
};