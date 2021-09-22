// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "TimelineManagerDecorator.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"

#include "GameLifeTimelineManager.generated.h"

/**
 * This decorator is fitted to track time when player plays since the game is launched.
 *
 * It used internally an FTimerManager to tick and to works accordingly with all time alterations (game pause, slowmo, ...).
 * It could be useful for bonus/malus attribution which works during the full game session.
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

	void GameTimerTick();

	/**
	 * It creates the timer with a FTimerManager and attached TimerDelegate to it.
	 * @param InTickInterval - The tick interval in seconds 
	 * @param InLabel - Name of the timer
	 */
	virtual void Init(const float& InTickInterval = 1.f, const FName& InLabel = NAME_None) override;

	/** Clears timer + unbind delegate + invalidate handle. */
	virtual void BeginDestroy() override;

	virtual void Clear() override;

	/** Only used to reset the SaveTime when loading */
	virtual void Serialize(FArchive& Ar) override;

protected:
	/** A default ctor for engine system */
	UNGameLifeTimelineManager();

	void OnLevelLoad(UWorld* LoadedWorld);

	/** This method to reset SaveTime when level changed */
	virtual void InternalLevelLoad(UWorld* LoadedWorld);

	/** Used to create an accurate delta time for ticks. */
	float SaveTime;
private:
};
