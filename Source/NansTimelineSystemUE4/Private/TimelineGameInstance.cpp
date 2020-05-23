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

#include "TimelineGameInstance.h"

#include "Manager/TimelineManagerBaseAdapter.h"

UNTimelineGameInstance::UNTimelineGameInstance() {}

void UNTimelineGameInstance::Init()
{
	Super::Init();
	InstanciateTimelinesFromConfig();
}

void UNTimelineGameInstance::InstanciateTimelinesFromConfig()
{
	TArray<FConfiguredTimeline> ConfigList;
	UNTimelineConfig::GetConfigs(ConfigList);

	for (auto& Conf : ConfigList)
	{
		UNTimelineManagerBaseAdapter* Timeline =
			UNTimelineManagerBaseAdapter::CreateObject<UNTimelineManagerBaseAdapter>(this, Conf.TimelineClass, Conf.Name);
		Timeline->Play();

		TimelinesCollection.Add(Conf.Name, Timeline);
	}
}

UNTimelineManagerBaseAdapter* UNTimelineGameInstance::GetTimeline(FConfiguredTimeline Config) const
{
	return GetTimeline(Config.Name);
}

UNTimelineManagerBaseAdapter* UNTimelineGameInstance::GetTimeline(FName Name) const
{
	if (!TimelinesCollection.Contains(Name))
	{
		UE_LOG(LogTemp, Error, TEXT("\"%s\" not exists in UNTimelineGameInstance::TimelinesCollection"), *Name.ToString());
		return nullptr;
	}

	return TimelinesCollection[Name];
}

void UNTimelineGameInstance::Serialize(FArchive& Ar)
{
	if (Ar.IsSaving())
	{
		for (auto& Timeline : TimelinesCollection)
		{
			SaveNamesOrder.Add(Timeline.Key);
		}
	}

	if (Ar.IsLoading())
	{
		// Refresh Timeline data, in case data has been set from previous load or game play.
		TimelinesCollection.Empty();
		InstanciateTimelinesFromConfig();
	}

	// This allows to check if there is a data delta between save game and load game
	// See the check below.
	Ar << SaveNamesOrder;

	for (auto& Name : SaveNamesOrder)
	{
		UNTimelineManagerBaseAdapter* Timeline = GetTimeline(Name);
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