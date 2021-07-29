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
#include "TimelineManagerDecorator.h"

#include "GameLifeTimelineManager.generated.h"

/**
 * This decorator is fitted to track time when player plays since the game is launched.
 *
 * It used internally an FTimerManager to tick and to works accordingly with all time alterations (game pause, slowmo, ...).
 * It could be usefull for bonus/malus attribution which works during the full game session.
 *
 * For example: Player makes a very benevolent actions which gives him a health bonus for 10 minutes in game.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNGameLifeTimelineManager : public UNTimelineManagerDecorator
{
	GENERATED_BODY()
public:
	/** Created by the FTimerManager */
	FTimerHandle TimerHandle;

	/** Delegate required by the FTimerManager. It create a UObject delegate using UNGameLifeTimelineManager::TimerTick()  */
	FTimerDelegate TimerDelegate;

	/**
	 * It creates the timer with a FTimerManager and attached TimerDelegate to it.
	 * @param InTickInterval - The tick interval in seconds 
	 * @param InLabel - Name of the timer
	 */
	virtual void Init(const float& InTickInterval = 1.f, const FName& InLabel = NAME_None) override;

	/**
	 * clears timer + unbind delegate + invalidate handle.
	 * @copydoc UNTimelineManagerDecorator::Clear()
	 */
	virtual void Clear() override;

protected:
	/** A default ctor for engine system */
	UNGameLifeTimelineManager();

	/** This is only used for savegame to keep time between sessions */
	UPROPERTY(SaveGame)
	float SaveTime;

private:
};
