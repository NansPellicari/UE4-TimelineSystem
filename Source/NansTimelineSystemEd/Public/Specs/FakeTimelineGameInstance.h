#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NansTimelineSystemUE4/Public/TimelineClient.h"
#include "NansTimelineSystemUE4/Public/TimelineGameInstance.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeGameInstance.h"

#include "FakeTimelineGameInstance.generated.h"

UCLASS(NotBlueprintable, NotPlaceable)
class NANSTIMELINESYSTEMED_API UNFakeTimelineGameInstance : public UFakeGameInstance, public INTimelineGameInstance
{
	GENERATED_BODY()
public:
	UNFakeTimelineGameInstance() {}

	virtual void Init() override
	{
		Super::Init();
		TimelineClient = NewObject<UNTimelineClient>(this, FName(TEXT("MyFakeTimelineClient")));
		TimelineClient->Init();
	}

	UNTimelineManagerDecorator* GetTimeline_Implementation(FConfiguredTimeline Config) const override
	{
		return TimelineClient->GetTimeline(Config);
	}

	virtual UNTimelineClient* GetTimelineClient_Implementation() const override
	{
		return TimelineClient;
	}

protected:
	UPROPERTY()
	UNTimelineClient* TimelineClient;
};
