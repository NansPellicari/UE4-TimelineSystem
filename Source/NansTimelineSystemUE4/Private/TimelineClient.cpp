// Copyright Nans Pellicari, 2021

#include "TimelineClient.h"

#include "Config/TimelineConfig.h"
#include "Manager/TimelineManagerDecorator.h"
#include "NansTimelineSystemUE4.h"

UNTimelineClient::UNTimelineClient() {}

void UNTimelineClient::Init()
{
	TArray<FConfiguredTimelineConf> ConfigList;
	UNTimelineConfig::GetConfigs(ConfigList);

	for (auto& Conf : ConfigList)
	{
		UNTimelineManagerDecorator* Timeline = FNTimelineManagerDecoratorFactory::CreateObject<
			UNTimelineManagerDecorator>(
			this, Conf.TimelineClass, Conf.TickInterval, Conf.Name
		);
		Timeline->bDebug = Conf.bDebug;
		Timeline->Play();

		TimelinesCollection.Add(Conf.Name, Timeline);
	}
}

UNTimelineManagerDecorator* UNTimelineClient::GetTimeline(FConfiguredTimeline Config) const
{
	return GetTimeline(Config.Name);
}

UNTimelineManagerDecorator* UNTimelineClient::GetTimeline(FName Name) const
{
	if (!TimelinesCollection.Contains(Name))
	{
		UE_LOG(
			LogTimelineSystem, Error, TEXT("\"%s\" not exists in UNTimelineClient::TimelinesCollection"),
			*Name.ToString()
		);
		return nullptr;
	}

	return TimelinesCollection[Name];
}

void UNTimelineClient::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (Ar.IsSaving())
	{
		for (auto& Timeline : TimelinesCollection)
		{
			SaveNamesOrder.AddUnique(Timeline.Key);
		}
	}

	if (Ar.IsLoading())
	{
		for (auto& It : TimelinesCollection)
		{
			It.Value->ConditionalBeginDestroy();
		}
		// Refresh Timeline data, in case data has been set from previous load or during game play.
		TimelinesCollection.Empty();
		Init();
	}

	// This allows to check if there is a data delta between save game and load game
	// See the check below.
	Ar << SaveNamesOrder;

	for (auto& Name : SaveNamesOrder)
	{
		UNTimelineManagerDecorator* Timeline = GetTimeline(Name);
		if (Timeline == nullptr)
		{
			UE_LOG(
				LogTimelineSystem,
				Error,
				TEXT("The timeline %s does not exists anymore, it can imply a binary shift on unserialization"),
				*Name.ToString()
			);
			continue;
		}

		Timeline->Serialize(Ar);
	}
}
