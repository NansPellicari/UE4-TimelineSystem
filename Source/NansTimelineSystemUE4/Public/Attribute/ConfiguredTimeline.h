// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "Templates/SubclassOf.h"

#include "ConfiguredTimeline.generated.h"

class UNTimelineManagerDecorator;

/**
 * This struct to create Configured Timeline and ease Timeline instantiation.
 * This allows to associated a Timeline Name to a class.
 */
USTRUCT(BlueprintType)
struct NANSTIMELINESYSTEMUE4_API FConfiguredTimeline
{
	GENERATED_BODY()

	/**
	 * This allows to retrieve easily a timeline.
	 * This is used by the SConfiguredTimelinePin as a combobox.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NansTimeline")
	FName Name;

	/** The Configured timeline class */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NansTimeline")
	TSubclassOf<UNTimelineManagerDecorator> TimelineClass;

	FORCEINLINE void Serialize(FArchive& Ar)
	{
		Ar << Name << TimelineClass;
	}

	FORCEINLINE uint32 GetTypeHash() const
	{
		return HashCombine(::GetTypeHash(Name), ::GetTypeHash(TimelineClass));
	}
};

FORCEINLINE uint32 GetTypeHash(const FConfiguredTimeline& Timeline)
{
	return Timeline.GetTypeHash();
}
