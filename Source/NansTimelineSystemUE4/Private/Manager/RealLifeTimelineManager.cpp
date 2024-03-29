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

#include "Manager/RealLifeTimelineManager.h"

UNRealLifeTimelineManager::UNRealLifeTimelineManager() {}

void UNRealLifeTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Super::Init(InTickInterval, InLabel);
	// Real life timer should be always in play state.
	State = ENTimelineTimerState::Played;
	if (CreationTime == 0)
	{
		CreationTime = FDateTime::Now();
	}
	LastPlayTime = FDateTime::Now();
}

void UNRealLifeTimelineManager::Tick(float DeltaTime)
{
	// this ensure to always get the real time delta (in case of slowmo).
	const float RealDelta = (FDateTime::Now() - LastPlayTime).GetTotalMilliseconds() / 1000;
	if (RealDelta >= GetTimeline()->GetTickInterval())
	{
		TotalLifeTime += RealDelta;
		TimerTick(RealDelta);
		LastPlayTime = FDateTime::Now();
	}
}

bool UNRealLifeTimelineManager::IsTickable() const
{
	return true;
}

UWorld* UNRealLifeTimelineManager::GetTickableGameObjectWorld() const
{
	if (GetWorld())
	{
		return GetWorld();
	}
	return nullptr;
}

void UNRealLifeTimelineManager::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	Ar << CreationTime;

	if (Ar.IsSaving())
	{
		LastPlayTime = FDateTime::Now();
	}

	Ar << LastPlayTime;

	if (Ar.IsLoading())
	{
		// Recover time between creation and last save game
		TotalLifeTime = (LastPlayTime - CreationTime).GetTotalSeconds();
		// Recover lost time since last save game
		float MissingLifeTime = (FDateTime::Now() - LastPlayTime).GetTotalSeconds();

		// Tick to notify timeline until it reaches the actual time.
		while (MissingLifeTime > 0)
		{
			TimerTick(GetTimeline()->GetTickInterval());
			MissingLifeTime -= GetTimeline()->GetTickInterval();
		}
		TotalLifeTime += (FDateTime::Now() - LastPlayTime).GetTotalSeconds();
		LastPlayTime = FDateTime::Now();
	}
}
