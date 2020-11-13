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
#include "NansTimelineSystemCore/Public/TimelineInterface.h"

#include "EventRecord.generated.h"

class NTimelineInterface;

/**
 * This struct is both a pass-through for NTimeline::FEventTuple
 * and a record object used for savegame.
 */
USTRUCT(BlueprintType)
struct NANSTIMELINESYSTEMUE4_API FNEventRecord
{
	GENERATED_USTRUCT_BODY()

public:
	FNEventRecord() {}
	FNEventRecord(const FNEventSave& Record)
	{
		UID = Record.UID;
		AttachedTime = Record.AttachedTime;
		Delay = Record.Delay;
		Duration = Record.Duration;
		LocalTime = Record.LocalTime;
		StartedAt = Record.StartedAt;
		Label = Record.Label;
		ExpiredTime = Record.ExpiredTime;
	}

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	FString UID = FString("");
	/** The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float AttachedTime = -1.f;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float StartedAt = -1.f;
	/** The delay before starting in secs */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Delay = -1.f;
	/** The duration this event lives in secs (0 means inderterminate) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Duration = -1.f;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float LocalTime = -1.f;
	/** The name of the event */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	FName Label = NAME_None;
	/** Expiration time of this event in secs (0 means can't expired)) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float ExpiredTime = -1.f;
};
