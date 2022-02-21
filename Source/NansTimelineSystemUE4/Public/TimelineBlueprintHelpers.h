// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "Attribute/ConfiguredTimeline.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "TimelineBlueprintHelpers.generated.h"

class UNEventBase;
class UNTimelineManagerDecorator;

/**
 * A simple Blueprint Library class to manage Timeline creation.
 */
UCLASS()
class NANSTIMELINESYSTEMUE4_API UNTimelineBlueprintHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * This class is a pass-through for the INTimelineGameInstance::GetTimeline() method.
	 * It provides a standalone node to avoid getting the game instance in your BP graph.
	 *
	 * @param WorldContextObject - This is as a Outer object for UNTimelineManagerDecorator instantiation, it is implicitly
	 * provided by kismet library thanks to UFUNCTION meta data "WorldContext"
	 * @param Timeline - To allow having a combobox of configured timelines
	 */
	// @formatter:off
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "Get a NansTimeline by its configured name", Keywords = "Timeline get"), Category = "NansTimeline")
	static UNTimelineManagerDecorator* GetTimeline(UObject* WorldContextObject, FConfiguredTimeline Timeline);
	// @formatter:on

	// @formatter:off
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Compare NansTimeline name", Keywords = "Timeline compare"), Category = "NansTimeline")
	static bool Compare(const FConfiguredTimeline Timeline1, const FConfiguredTimeline Timeline2);
	// @formatter:on

	// @formatter:off
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get NansTimeline name", Keywords = "Timeline get name"), Category = "NansTimeline")
	static FName GetName(const FConfiguredTimeline Timeline);
	// @formatter:on
};
