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
#include "TimelineManagerDecorator.h"

#include "LevelLifeTimelineManager.generated.h"

/**
 * It tracks game session but refreshes when level changed.
 *
 * It could be useful for level bonus/malus attribution during a level session, or create a scheduled event.
 *
 * For example:
 * - a player character take drugs and his capacities are altered for an amount of time
 * - player init a bomb and it should explode in a determined time.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNLevelLifeTimelineManager final : public UNGameLifeTimelineManager
{
	GENERATED_BODY()
public:
	/**
	 * Attaches event on level changes
	 * @copydoc UNTimelineManagerDecorator::Init()
	 */
	virtual void Init(const float& InTickInterval = 1.f, const FName& InLabel = NAME_None) override;

	/** This method to clear and reload timeline when level changed */
	void OnLevelRemoved(ULevel* Level, UWorld* World);

	/** @copydoc OnLevelRemoved */
	void OnLevelChanged(UWorld* LoadedWorld);

	/** This only saves level name and checks */
	virtual void Serialize(FArchive& Ar) override;

	virtual void BeginDestroy() override;

protected:
	/** Default ctor */
	UNLevelLifeTimelineManager();

	/** TODO WIP */
	void SaveDataAndClear();

	/** Used for save game object */
	UPROPERTY()
	FName Label;

	/** Used for save game to make a sanity check (verify if current world is the same as the load game) */
	UPROPERTY()
	FString LevelName;

private:
};
