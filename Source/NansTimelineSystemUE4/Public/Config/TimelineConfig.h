// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"
#include "Manager/TimelineManagerDecorator.h"

#include "TimelineConfig.generated.h"

/**
 * This struct to create Configured Timeline and ease Timeline instantiation.
 * This allows to associated a Timeline Name to a class.
 */
USTRUCT(BlueprintType)
struct NANSTIMELINESYSTEMUE4_API FConfiguredTimelineConf
{
	GENERATED_BODY()

	/**
	 * This allows to retrieve easily a timeline.
	 * This is used by the SConfiguredTimelinePin as a combobox.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NansTimeline")
	FName Name;

	/** The Configured Timeline class */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NansTimeline")
	TSubclassOf<UNTimelineManagerDecorator> TimelineClass;

	/** You can use this to add more or less frequency between each tick. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NansTimeline")
	float TickInterval = 1.f;

	/** Will debug this timeline */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NansTimeline")
	bool bDebug = false;
};

/**
 * A simple configuration to ease timeline instantiation for developers.
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Nans Timeline"))
class NANSTIMELINESYSTEMUE4_API UNTimelineConfig : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, Category = "NansTimeline")
	TArray<FConfiguredTimelineConf> ConfiguredTimeline;

	/**
	 * Retrieve config from developers choices.
	 */
	static void GetConfigs(TArray<FConfiguredTimelineConf>& ShareableNames)
	{
		const UNTimelineConfig* StaticObject = GetDefault<UNTimelineConfig>();
		for (FConfiguredTimelineConf Config : StaticObject->ConfiguredTimeline)
		{
			ShareableNames.Add(Config);
		}
	}
};
