// Copyright Nans Pellicari, 2021

#include "Manager/GameLifeTimelineManager.h"

#include "Runtime/Engine/Classes/Engine/World.h"
#include "TimerManager.h"

UNGameLifeTimelineManager::UNGameLifeTimelineManager() {}

void UNGameLifeTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Super::Init(InTickInterval, InLabel);
	TimerDelegate = FTimerDelegate::CreateUObject(this, &UNGameLifeTimelineManager::GameTimerTick);
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, TimerDelegate, GetTimeline()->GetTickInterval(), true);
	SaveTime = GetWorld()->GetTimeSeconds();
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UNGameLifeTimelineManager::OnLevelLoad);
}

void UNGameLifeTimelineManager::OnLevelLoad(UWorld* LoadedWorld)
{
	InternalLevelLoad(LoadedWorld);
}

void UNGameLifeTimelineManager::InternalLevelLoad(UWorld* LoadedWorld)
{
	SaveTime = 0;
}

void UNGameLifeTimelineManager::GameTimerTick()
{
	const float NewTime = GetWorld()->GetTimeSeconds();
	TimerTick(NewTime - SaveTime);
	SaveTime = NewTime;
}

void UNGameLifeTimelineManager::BeginDestroy()
{
	if (IsValid(GetWorld()))
	{
		FTimerManager& TimerManager = GetWorld()->GetTimerManager();
		TimerManager.ClearTimer(TimerHandle);
	}

	SaveTime = 0;

	FCoreUObjectDelegates::PostLoadMapWithWorld.RemoveAll(this);
	TimerDelegate.Unbind();
	TimerHandle.Invalidate();
	Super::BeginDestroy();
}

void UNGameLifeTimelineManager::Clear()
{
	SaveTime = 0;
	Super::Clear();
}

void UNGameLifeTimelineManager::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (Ar.IsLoading())
	{
		SaveTime = GetWorld()->GetTimeSeconds();
	}
}
