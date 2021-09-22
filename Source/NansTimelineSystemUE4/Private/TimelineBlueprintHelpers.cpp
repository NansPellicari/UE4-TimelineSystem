// Copyright Nans Pellicari, 2021

#include "TimelineBlueprintHelpers.h"

#include "Engine.h"
#include "TimelineGameSubsystem.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Attribute/ConfiguredTimeline.h"

UNTimelineManagerDecorator* UNTimelineBlueprintHelpers::GetTimeline(UObject* WorldContextObject, FConfiguredTimeline Timeline)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;

	UGameInstance* GI = World->GetGameInstance();
	UTimelineGameSubsystem* MySubsystem = GI->GetSubsystem<UTimelineGameSubsystem>();
	
	check(MySubsystem != nullptr);

	return MySubsystem->GetTimeline(Timeline);
}

bool UNTimelineBlueprintHelpers::Compare(const FConfiguredTimeline Timeline1, const FConfiguredTimeline Timeline2)
{
	return Timeline1.Name == Timeline2.Name;
}

FName UNTimelineBlueprintHelpers::GetName(const FConfiguredTimeline Timeline)
{
	return Timeline.Name;
}
