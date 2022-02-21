// Copyright Nans Pellicari, 2021

#include "TimelineGameSubsystem.h"

#include "TimelineClient.h"
#include "Attribute/ConfiguredTimeline.h"


void UTimelineGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Client = NewObject<UNTimelineClient>(this, FName(TEXT("MyTimelineClient")));
	Client->Init();
}

UNTimelineManagerDecorator* UTimelineGameSubsystem::GetTimeline(
	FConfiguredTimeline Timeline) const
{
	return Client->GetTimeline(Timeline);
}

UNTimelineManagerDecorator* UTimelineGameSubsystem::GetTimeline(FName Timeline) const
{
	return Client->GetTimeline(Timeline);
}

UNTimelineClient* UTimelineGameSubsystem::GetTimelineClient() const
{
	return Client;
}

void UTimelineGameSubsystem::Deinitialize()
{
	Client->ConditionalBeginDestroy();
}
