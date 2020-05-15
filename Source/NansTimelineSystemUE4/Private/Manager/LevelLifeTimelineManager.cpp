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

#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TimerManager.h"

UNLevelLifeTimelineManager::UNLevelLifeTimelineManager() {}

void UNLevelLifeTimelineManager::Init(FName _Label)
{
	Super::Init(_Label);

	// Save it here cause we clear all datas when level events are triggered.
	Label = _Label;
	GetWorld()->OnSelectedLevelsChanged().AddUObject(this, &UNLevelLifeTimelineManager::OnLevelChanged);
	// FWorldDelegates::LevelAddedToWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
	FWorldDelegates::LevelRemovedFromWorld.AddUObject(this, &UNLevelLifeTimelineManager::OnLevelRemoved);
}

void UNLevelLifeTimelineManager::OnLevelChanged()
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
	SaveDataAndClear();
	Init(Label);
}

void UNLevelLifeTimelineManager::OnLevelRemoved(ULevel* Level, UWorld* World)
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Warning, TEXT("%s is called !!!"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
	SaveDataAndClear();
	Init(Label);
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
	if (Ar.IsLoading())
	{
		// This is just a safety check, but it shoulds never happens.
		// The savegame shoulds associate the level (UWorld) AND this timeline
		if (LevelName.IsEmpty()) return;
		if (GetWorld() == nullptr) return;
		if (GetWorld()->GetName() != LevelName) return;
	}

	Super::Serialize(Ar);
}

void UNLevelLifeTimelineManager::Clear()
{
	Super::Clear();
	FWorldDelegates::LevelRemovedFromWorld.RemoveAll(this);
	FWorldDelegates::LevelAddedToWorld.RemoveAll(this);
	if (GetWorld() != nullptr)
	{
		GetWorld()->OnSelectedLevelsChanged().RemoveAll(this);
	}
}