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

#include "Config/TimelineConfig.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "TimelineGameInstance.generated.h"

class UNTimelineManagerBaseDecorator;

/**
 * This is a based class which need to be instanciated to get all the timeline configuration system works.
 *
 * This is the main client which instances Configured Timeline (UNTimelineConfig)
 * and UNTimelineBlueprintHelpers::CreateAndAttachedEvent() used.
 *
 * @see UNTimelineBlueprintHelpers::CreateAndAttachedEvent().
 * @see UNTimelineConfig to get more details on the configuration.
 * @see FConfiguredTimeline to see how to use Configured Timeline as blueprint pins.
 * @see
 */
UCLASS(Blueprintable, Category = "NansTimeline")
class NANSTIMELINESYSTEMUE4_API UNTimelineGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UNTimelineGameInstance();
	virtual void Init() override;

	/**
	 * A blueprint pass-through for GetTimeline(FName Name).
	 *
	 * @param Config - To allow having a combobox of configured timeline
	 */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline")
	UNTimelineManagerBaseDecorator* GetTimeline(FConfiguredTimeline Config) const;

	/**
	 * Get the timeline from TimelinesCollection by its name.
	 *
	 * @param Name - The name of the timeline
	 */
	UNTimelineManagerBaseDecorator* GetTimeline(FName Name) const;

	/**
	 * It used to save all timelines in the EventStore,
	 * and reload them correctly.
	 *
	 * @param Ar - Archive for save and load
	 */
	virtual void Serialize(FArchive& Ar) override;

protected:
	/**
	 * This method allows to instanciate all Timeline from the config: FConfiguredTimeline.
	 *
	 * @see FConfiguredTimeline
	 */
	void InstanciateTimelinesFromConfig();

	/**
	 * Collection of timelines instanciated by InstanciateTimelinesFromConfig()
	 */
	UPROPERTY(SkipSerialization)
	TMap<FName, UNTimelineManagerBaseDecorator*> TimelinesCollection;

private:
	/**
	 * This is just an helper for the savegame.
	 * Thanks to this we can check if there is a delta between save and load then alert client.
	 */
	UPROPERTY(SkipSerialization)
	TArray<FName> SaveNamesOrder;
};
