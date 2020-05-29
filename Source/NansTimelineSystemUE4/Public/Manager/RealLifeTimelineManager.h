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
#include "Runtime/Engine/Public/Tickable.h"
#include "TimelineManagerDecorator.h"

#include "RealLifeTimelineManager.generated.h"

/**
 * It tracks realtime, it is not altered by pause or slowmo.
 *
 * It could be useful for creating some bonus/malus which has a determinate times.
 *
 * For example: A promo code which gives a market discount for 2 days.
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNRealLifeTimelineManager : public UNTimelineManagerDecorator, public FTickableGameObject
{
	GENERATED_BODY()
public:
	/** This do nothing. Excepts in our deepest dreams, we can't altered time in real life!! */
	virtual void Pause() override{};

	/** @copydoc Pause() */
	virtual void Play() override{};

	/** @copydoc Pause() */
	virtual void Stop() override{};

	/**
	 * This just init State to "Play" and time variables.
	 * @copydoc UNTimelineManagerDecorator::Init()
	 */
	virtual void Init(float _TickInterval = 1.f, FName _Label = NAME_None) override;

	// BEGIN FTickableGameObject override
	/** Always returns true 'cause it can be paused or stopped */
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}

	/** Always returns true 'cause it can be paused or stopped */
	virtual bool IsTickable() const override;

	/**
	 * This override methods allows to tick UNTimelineManagerDecorator::TimerTick()
	 * and to increment times vars.
	 *
	 * @param DeltaTime - It is not used here, it used FDateTime::Now() - LastPlayTime to compute the real life delta time
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * Required by FTickableGameObject.
	 * @copydoc FTickableObjectBase::GetStatId()
	 */
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(TimelineManagerTickableOnPause, STATGROUP_Tickables);
	}
	virtual UWorld* GetTickableGameObjectWorld() const override;
	// END FTickableGameObject override

	/**
	 * Used for save to retrieve last datetime and save it,
	 * for load to compute missing time during last saves and ticks accordingly.
	 *
	 * @param Ar - Used to saved binary data.
	 */
	virtual void Serialize(FArchive& Ar) override;

	/** It should be set only the first time the game is launched. */
	UPROPERTY(BlueprintReadOnly, SaveGame)
	FDateTime CreationTime;

protected:
	/** It tracks time (secs) since it has been created */
	float TotalLifeTime = 0;
	/** It tracks time (FDateTime) since it has been created */
	FDateTime LastPlayTime;

	/**
	 * It tracks time (FDateTime) since timeline has been ticked
	 * @see Tick() for usage.
	 */
	float LastTimeTick = 0;

	/** Default ctor */
	UNRealLifeTimelineManager();

private:
};
