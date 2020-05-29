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

#include "Attribute/ConfiguredTimeline.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "TimelineGameInstance.generated.h"

class UNTimelineClient;
class UNTimelineManagerDecorator;

/** @see INTimelineGameInstance */
UINTERFACE(MinimalAPI, BlueprintType)
class UNTimelineGameInstance : public UInterface
{
	GENERATED_BODY()
};

/**
 * This interface should be implemented by your GameInstance class or blueprint object.
 * See README.md in step by step guide to see how to implements it.
 */
class NANSTIMELINESYSTEMUE4_API INTimelineGameInstance
{
	GENERATED_BODY()

public:
	/**
	 * A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).
	 *
	 * @param Timeline - To allow having a combobox of configured timelines
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (DisplayName = "Get a NansTimeline"), Category = "NansTimeline")
	UNTimelineManagerDecorator* GetTimeline(FConfiguredTimeline Timeline) const;

	virtual UNTimelineClient* GetClient() const;
};
