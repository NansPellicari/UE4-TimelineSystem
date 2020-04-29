#include "Manager/RealLifeTimelineManager.h"

#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "TimerManager.h"

UNRealLifeTimelineManager::UNRealLifeTimelineManager() {}

void UNRealLifeTimelineManager::Init()
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNRealLifeTimelineManager need a world to live"));
}

void UNRealLifeTimelineManager::Tick(float DeltaTime)
{
	TotalLifeTime += DeltaTime;
	if (FMath::IsNearlyEqual(TotalLifeTime - LastTimeTick, GetTickInterval(), 0.001f))
	{
		LastTimeTick = TotalLifeTime;
		TimerTick();
	}
}

bool UNRealLifeTimelineManager::IsTickable() const
{
	return State != ENTimelineTimerState::Played ? false : true;
}

UWorld* UNRealLifeTimelineManager::GetTickableGameObjectWorld() const
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNRealLifeTimelineManager need a world to live"));
	return GetWorld();
}
