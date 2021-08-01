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

#include "Subsystems/GameInstanceSubsystem.h"
#include "TimelineGameSubsystem.generated.h"

struct FConfiguredTimeline;
class UNTimelineManagerDecorator;
class UNTimelineClient;

UCLASS()
class NANSTIMELINESYSTEMUE4_API UTimelineGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	/**
	* A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).
	*
	* @param Timeline - To allow having a combobox of configured timelines
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get a NansTimeline"), Category = "NansTimeline")
	UNTimelineManagerDecorator* GetTimeline(FConfiguredTimeline Timeline) const;

	// @formatter:off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the NansTimeline client"), Category = "NansTimeline")
	UNTimelineClient* GetTimelineClient() const;
	// @formatter:on
	
private:
	UPROPERTY()
	UNTimelineClient* Client;
};
