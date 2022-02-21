// Copyright Nans Pellicari, 2021

#include "Manager/LevelLifeTimelineManager.h"

#include "Runtime/Engine/Classes/Engine/World.h"
#include "NansTimelineSystemUE4.h"

UNLevelLifeTimelineManager::UNLevelLifeTimelineManager() {}

void UNLevelLifeTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	SaveTime = 0.f;
	Super::Init(InTickInterval, InLabel);
	// Save it here cause we clear all datas when level events are triggered.
	Label = InLabel;
	
	FWorldDelegates::LevelRemovedFromWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
}

void UNLevelLifeTimelineManager::InternalLevelLoad(UWorld* LoadedWorld)
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTimelineSystem, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
	SaveDataAndClear();
}

void UNLevelLifeTimelineManager::OnLevelRemoved(ULevel* Level, UWorld* World)
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTimelineSystem, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
	SaveDataAndClear();
}

void UNLevelLifeTimelineManager::SaveDataAndClear()
{
	// TODO Should serialized first, save in user stats then clear
	Clear();
}

void UNLevelLifeTimelineManager::Serialize(FArchive& Ar)
{
	if (Ar.IsSaving() && GetWorld() != nullptr)
	{
		LevelName = GetWorld()->GetName();
	}

	Ar << LevelName;

	bool bShouldBeCleared = false;

	if (Ar.IsLoading())
	{
		// This is just a safety check, but it should never happens.
		// The savegame should associate the level (UWorld) AND this timeline
		if (LevelName.IsEmpty()) bShouldBeCleared = true;
		if (GetWorld() == nullptr) bShouldBeCleared = true;
		if (GetWorld() != nullptr && GetWorld()->GetName() != LevelName) bShouldBeCleared = true;
	}

	// This have to be serialized even if wrong data has been retrieved
	// (IsLoading() conditions above) to avoid a binary shift on deserialization.
	Super::Serialize(Ar);

	if (bShouldBeCleared)
	{
		Clear();
	}
}

void UNLevelLifeTimelineManager::BeginDestroy()
{
	FWorldDelegates::LevelRemovedFromWorld.RemoveAll(this);
	Super::BeginDestroy();
}