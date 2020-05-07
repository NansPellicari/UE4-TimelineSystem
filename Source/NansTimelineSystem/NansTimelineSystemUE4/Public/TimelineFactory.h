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

#include "TimelineFactory.generated.h"

class UNTimelineManagerBase;
class UNTimelineEventAdapter;

/**
 *
 */
UCLASS()
class NANSTIMELINESYSTEMUE4_API UTimelineFactory : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	// clang-format off
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DisplayName = "Create a New Timeline", Keywords = "Timeline create"), Category = "TimelineSystem")
	static UNTimelineManagerBase* CreateNewTimeline(UObject* WorldContextObject, TSubclassOf<UNTimelineManagerBase> Class, FName Name);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DisplayName = "Create a New Event for timeline", Keywords = "Event create"), Category = "TimelineSystem")
	static UNTimelineEventAdapter* CreateNewEvent(UObject* WorldContextObject, TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Delay = 0);
	// clang-format on
};
