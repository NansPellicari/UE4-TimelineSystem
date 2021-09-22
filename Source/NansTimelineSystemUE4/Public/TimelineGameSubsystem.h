// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "Manager/TimelineManagerDecorator.h"

#include "TimelineGameSubsystem.generated.h"

struct FConfiguredTimeline;

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

	/**
	* A blueprint pass-through for UNTimelineClient::GetTimeline(FName Config).
	*
	* @param Timeline - name of the timeline
	*/
	UNTimelineManagerDecorator* GetTimeline(FName Timeline) const;

	// @formatter:off
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the NansTimeline client"), Category = "NansTimeline")
	UNTimelineClient* GetTimelineClient() const;
	// @formatter:on
	
private:
	UPROPERTY()
	UNTimelineClient* Client;
};
