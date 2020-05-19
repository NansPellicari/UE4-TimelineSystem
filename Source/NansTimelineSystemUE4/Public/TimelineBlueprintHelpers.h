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
#include "Kismet/BlueprintFunctionLibrary.h"

#include "TimelineBlueprintHelpers.generated.h"

class UNTimelineManagerBaseAdapter;
class UNTimelineEventAdapter;

/**
 * A simple Blueprint Library class to manage Timeline creation.
 */
UCLASS()
class NANSTIMELINESYSTEMUE4_API UNTimelineBlueprintHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * It allows you to create a new timeline manager with its embeded timeline.
	 *
	 * @param WorldContextObject - This is as a Outer object for UNTimelineManagerBaseAdapter instanciation, it is implicitly
	 * provided by kismet library thanks to UFUNCTION meta data "WorldContext"
	 * @param Class - The class you want to instanciate
	 * @param Name - The name of your timeline
	 */
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DisplayName = "Create a New Timeline", Keywords = "Timeline create"), Category = "NansTimeline")
	static UNTimelineManagerBaseAdapter* CreateNewTimeline(UObject* WorldContextObject, TSubclassOf<UNTimelineManagerBaseAdapter> Class, FName Name);
	// clang-format on
};
