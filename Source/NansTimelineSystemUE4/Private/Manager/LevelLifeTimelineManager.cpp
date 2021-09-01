// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Manager/LevelLifeTimelineManager.h"

#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TimerManager.h"

UNLevelLifeTimelineManager::UNLevelLifeTimelineManager() {}

void UNLevelLifeTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Super::Init(InTickInterval, InLabel);
	// Save it here cause we clear all datas when level events are triggered.
	Label = InLabel;
#if WITH_EDITOR
	GetWorld()->OnSelectedLevelsChanged().AddUObject(this, &UNLevelLifeTimelineManager::OnLevelChanged);
#endif

	// FWorldDelegates::LevelAddedToWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
	FWorldDelegates::LevelRemovedFromWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
}

void UNLevelLifeTimelineManager::OnLevelChanged()
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
	SaveDataAndClear();
	Init(TickInterval, Label);
}

void UNLevelLifeTimelineManager::OnLevelRemoved(ULevel* Level, UWorld* World)
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
	SaveDataAndClear();
	Init(TickInterval, Label);
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
		// This is just a safety check, but it shoulds never happens.
		// The savegame shoulds associate the level (UWorld) AND this timeline
		if (LevelName.IsEmpty()) bShouldBeCleared = true;
		if (GetWorld() == nullptr) bShouldBeCleared = true;
		if (GetWorld() != nullptr && GetWorld()->GetName() != LevelName) bShouldBeCleared = true;
	}

	// This have to be serialized even if wrong data has been retrieved
	// (IsLoading() conditions above) to avoid a binary shift on unserialization.
	Super::Serialize(Ar);

	if (bShouldBeCleared)
	{
		Clear();
		Init(TickInterval, Label);
	}
}

void UNLevelLifeTimelineManager::Clear()
{
	FWorldDelegates::LevelRemovedFromWorld.RemoveAll(this);
	FWorldDelegates::LevelAddedToWorld.RemoveAll(this);

#if WITH_EDITOR
	if (IsValid(GetWorld()))
	{
		GetWorld()->OnSelectedLevelsChanged().RemoveAll(this);
	}
#endif
	UNGameLifeTimelineManager::Clear();
}
