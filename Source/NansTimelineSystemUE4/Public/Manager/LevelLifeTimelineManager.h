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

#pragma once

#include "CoreMinimal.h"
#include "GameLifeTimelineManager.h"
#include "TimelineManagerBaseAdapter.h"

#include "LevelLifeTimelineManager.generated.h"

/**
 * It tracks game session but refreshes when level changed.
 *
 * It could be usefull for level bonus/malus attribution during a level session, or create a sheduled event.
 *
 * For example:
 * - a player character take drugs and his capacities are altered for an amount of time
 * - player init a bomb and it should explosed in a determined time.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNLevelLifeTimelineManager : public UNGameLifeTimelineManager
{
	GENERATED_BODY()
public:
	/**
	 * Attaches event on level changes
	 * @copydoc UNGameLifeTimelineManager::Init()
	 */
	virtual void Init(FName _Label = NAME_None) override;

	/** This method to clear and reload timeline when level changed */
	void OnLevelRemoved(ULevel* Level, UWorld* World);

	/** @copydoc OnLevelRemoved */
	void OnLevelAdded(ULevel* Level, UWorld* World);

	/** @copydoc OnLevelRemoved */
	void OnLevelChanged();

	/**
	 * Removes all attached events
	 * @copydoc UNGameLifeTimelineManager::Clear()
	 */
	virtual void Clear() override;

	/** This only saves level name and checks */
	virtual void Serialize(FArchive& Ar) override;

protected:
	/** Default ctor */
	UNLevelLifeTimelineManager();

	/** WIP */
	void SaveDataAndClear();

	/** Used for savegame */
	UPROPERTY()
	FName Label;

	/** Used for savegame to make a sanity check (verify if current world is the same as the load game) */
	UPROPERTY()
	FString LevelName;

private:
};
