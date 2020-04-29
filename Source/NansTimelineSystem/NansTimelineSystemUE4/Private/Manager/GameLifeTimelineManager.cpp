#include "Manager/GameLifeTimelineManager.h"

#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TimerManager.h"

UNGameLifeTimelineManager::UNGameLifeTimelineManager() {}

void UNGameLifeTimelineManager::Init()
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNGameLifeTimelineManager need a world to live"));
	Super::Init();
	TimerDelegate = FTimerDelegate::CreateUObject(this, &UNGameLifeTimelineManager::TimerTick);
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, TimerDelegate, GetTickInterval(), true);
}

void UNGameLifeTimelineManager::Clear()
{
	Super::Clear();
	check(GetWorld());
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.ClearTimer(TimerHandle);
	TimerDelegate.Unbind();
	TimerHandle.Invalidate();
}
