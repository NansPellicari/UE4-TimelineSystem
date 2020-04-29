#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "TimelineManagerBase.h"

#include "RealLifeTimelineManager.generated.h"

UCLASS()
class NANSTIMELINESYSTEMUE4_API UNRealLifeTimelineManager : public UNTimelineManagerBase, public FTickableGameObject
{
	GENERATED_BODY()
public:
	virtual void Init() override;

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

protected:
	float TotalLifeTime = 0;
	float LastTimeTick = 0;

	UNRealLifeTimelineManager();

private:
};
