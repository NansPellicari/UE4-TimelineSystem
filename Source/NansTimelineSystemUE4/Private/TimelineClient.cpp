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

#include "TimelineClient.h"

#include "Manager/TimelineManagerDecorator.h"

UNTimelineClient::UNTimelineClient() {}

void UNTimelineClient::Init()
{
	TArray<FConfiguredTimelineConf> ConfigList;
	UNTimelineConfig::GetConfigs(ConfigList);

	for (auto& Conf : ConfigList)
	{
		UNTimelineManagerDecorator* Timeline = UNTimelineManagerDecoratorFactory::CreateObject<UNTimelineManagerDecorator>(
			this, Conf.TimelineClass, Conf.TickInterval, Conf.Name);
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
		UE_LOG(LogTemp, Error, TEXT("\"%s\" not exists in UNTimelineClient::TimelinesCollection"), *Name.ToString());
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
			UE_LOG(LogTemp,
				Error,
				TEXT("The timeline %s does not exists anymore, it can imply a binary shift on unserialization"),
				*Name.ToString());
			continue;
		}

		Timeline->Serialize(Ar);
	}
}
