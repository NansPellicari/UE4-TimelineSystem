#include "Manager/LevelLifeTimelineManager.h"

#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TimerManager.h"

UNLevelLifeTimelineManager::UNLevelLifeTimelineManager() {}
void UNLevelLifeTimelineManager::Init()
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNRealLifeTimelineManager need a world to live"));
	Super::Init();
	GetWorld()->OnSelectedLevelsChanged().AddUObject(this, &UNLevelLifeTimelineManager::OnLevelChanged);
	FWorldDelegates::LevelAddedToWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
	FWorldDelegates::LevelRemovedFromWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
}

void UNLevelLifeTimelineManager::OnLevelChanged()
{
	// UE_LOG(LogTemp, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
	SaveDataAndClear();
	Init();
}
void UNLevelLifeTimelineManager::OnLevelRemoved(ULevel* Level, UWorld* World)
{
	// UE_LOG(LogTemp, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
	SaveDataAndClear();
}

void UNLevelLifeTimelineManager::SaveDataAndClear()
{
	// TODO Should serialized first, save in user stats then clear
	Clear();
}

void UNLevelLifeTimelineManager::Clear()
{
	Super::Clear();
	FWorldDelegates::LevelRemovedFromWorld.RemoveAll(this);
	FWorldDelegates::LevelAddedToWorld.RemoveAll(this);
	GetWorld()->OnSelectedLevelsChanged().RemoveAll(this);
}