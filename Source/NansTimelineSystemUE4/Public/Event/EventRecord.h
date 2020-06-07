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
#include "Event/EventDecorator.h"
#include "NansTimelineSystemCore/Public/EventInterface.h"

#include "EventRecord.generated.h"

class UNTimelineManagerDecorator;
class UNTimelineDecorator;

/**
 * This struct is both a pass-through for NTimeline::FEventTuple
 * and a record object used for savegame.
 */
USTRUCT(BlueprintType)
struct NANSTIMELINESYSTEMUE4_API FNEventRecord
{
	GENERATED_USTRUCT_BODY()

	FNEventRecord() {}

	/** The UNEventDecorator object */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	UNEventDecorator* Event = nullptr;
	/** The UNEventDecorator UId, it can be used to create consistant link to an object that envelops and EventDecorator */
	UPROPERTY(SkipSerialization)
	FString UId = FString("");
	/** The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float AttachedTime = -1.f;
	/** The delay before starting in secs */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Delay = -1.f;
	/** The duration this event lives in secs (0 means inderterminate) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Duration = -1.f;
	/** The name of the event */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	FName Label = NAME_None;
	/** Expiration time of this event in secs (0 means can't expired)) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float ExpiredTime = -1.f;
	/** This is used only for serialization, it allow to re-instance the object on load */
	UPROPERTY(SkipSerialization)
	FString EventClassName = FString("");

	/** It manages Event object saving and loading */
	void Serialize(FArchive& Ar, UNTimelineDecorator* Timeline);

	/** Just save basic data, see FNEventRecord::Serialize() to see how Event object is managed */
	friend FArchive& operator<<(FArchive& Ar, FNEventRecord& Record)
	{
		if (Ar.IsSaving())
		{
			Record.EventClassName = Record.Event != nullptr ? Record.Event->GetClass()->GetPathName() : FString("");
		}

		Ar << Record.UId;
		Ar << Record.EventClassName;
		Ar << Record.AttachedTime;
		Ar << Record.Delay;
		Ar << Record.Duration;
		Ar << Record.Label;
		Ar << Record.ExpiredTime;

		return Ar;
	};
};
