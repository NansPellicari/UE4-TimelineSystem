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

#include "Attribute/ConfiguredTimeline.h"

#include "TimelineClient.generated.h"

class UNTimelineManagerDecorator;

/**
 * This class should be used by your GameInstance object.
 * This object is the glue for all the timeline configuration and blueprint helpers.
 *
 * This is the main client which instances timelines from your settings (using UNTimelineConfig)
 * and uses by blueprint helpers lib UNTimelineBlueprintHelpers.
 *
 * @see INTimelineGameInstance.
 * @see UNTimelineConfig to get more details on the configuration.
 * @see FConfiguredTimeline to see how to use Configured Timeline as blueprint pins.
 */
UCLASS(Blueprintable, Category = "NansTimeline")
class NANSTIMELINESYSTEMUE4_API UNTimelineClient : public UObject
{
	GENERATED_BODY()
public:
	UNTimelineClient();

	/**
	 * This method allows to instantiate all Timeline from the config: FConfiguredTimeline.
	 *
	 * @see FConfiguredTimeline
	 */
	UFUNCTION(BlueprintCallable, Category = "NansTimeline")
	virtual void Init();

	/**
	 * A blueprint pass-through for GetTimeline(FName Name).
	 *
	 * @param Config - To allow having a combobox of configured timeline
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetANansTimeline"), Category = "NansTimeline")
	UNTimelineManagerDecorator* GetTimeline(FConfiguredTimeline Config) const;

	/**
	 * Get the timeline from TimelinesCollection by its name.
	 *
	 * @param Name - The name of the timeline
	 */
	UNTimelineManagerDecorator* GetTimeline(FName Name) const;

	/**
	 * It used to save all timelines in the TimelinesCollection,
	 * and reload them correctly.
	 *
	 * @param Ar - Archive for save and load
	 */
	virtual void Serialize(FArchive& Ar) override;

protected:
	/**
	 * Collection of timelines instantiated in Init()
	 */
	UPROPERTY(SkipSerialization)
	TMap<FName, UNTimelineManagerDecorator*> TimelinesCollection;

private:
	/**
	 * This is just an helper for the savegame.
	 * Thanks to this we can check if there is a delta between save and load then alert client.
	 */
	UPROPERTY(SkipSerialization)
	TArray<FName> SaveNamesOrder;
};
