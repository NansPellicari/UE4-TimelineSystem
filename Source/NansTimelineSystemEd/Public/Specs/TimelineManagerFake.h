// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NansTimelineSystemCore/Public/TimelineManager.h"
#include "TimerManager.h"

/**
 * This class is used for tests only
 */
class FNTimelineManagerFake final : public FNTimelineManager
{
public:
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	float Counter = 0;

	FNTimelineManagerFake()
	{
		TimerDelegate = FTimerDelegate::CreateRaw(this, &FNTimelineManagerFake::OnTimerTick);
	}

	void OnTimerTick()
	{
		TimerTick(GetTimeline()->GetTickInterval());
	}
	virtual void OnNotifyTimelineTickBefore(const float& InDeltaTime) override
	{
		Counter++;
		UE_LOG(LogTemp, Display, TEXT("%s - tick %f"), ANSI_TO_TCHAR(__FUNCTION__), Counter);
	}

	virtual void Clear() override
	{
		TimerDelegate.Unbind();
		TimerHandle.Invalidate();
	}
};
