#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NansTimelineSystemCore/Public/TimelineManagerBase.h"
#include "TimerManager.h"

/**
 * This class is used for tests only
 */
class NTimelineManagerFake : public NTimelineManagerBase
{
public:
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	float Counter = 0;

	NTimelineManagerFake()
	{
		TimerDelegate = FTimerDelegate::CreateRaw(this, &NTimelineManagerFake::TimerTick);
	}

	virtual void onNotifyTimelineTickBefore() override
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