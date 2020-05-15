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

#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "TimerManager.h"

UNRealLifeTimelineManager::UNRealLifeTimelineManager() {}

void UNRealLifeTimelineManager::Init(FName _Label)
{
	Super::Init(_Label);
	// Real life timer should be always in play state.
	State = ENTimelineTimerState::Played;
	if (CreationTime == 0)
	{
		CreationTime = FDateTime::Now();
	}
	LastTimeTick = TotalLifeTime;
	LastPlayTime = FDateTime::Now();
}

void UNRealLifeTimelineManager::Tick(float DeltaTime)
{
	// this ensure to always get the real time delta (in case of slowmo).
	float RealDelta = (FDateTime::Now() - LastPlayTime).GetTotalMilliseconds() / 1000;
	TotalLifeTime += RealDelta;
	if (TotalLifeTime - LastTimeTick >= GetTickInterval())
	{
		LastTimeTick += GetTickInterval();
		TimerTick();
	}
	LastPlayTime = FDateTime::Now();
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
		LastTimeTick = TotalLifeTime;
		// Recover lost time since last save game
		float MissingLifeTime = (FDateTime::Now() - LastPlayTime).GetTotalSeconds() / GetTickInterval();
		const float SliceTime = GetTickInterval() / 10;

		// Tick to notify timeline until it reaches the actual time.
		while (MissingLifeTime > 0)
		{
			Tick(SliceTime);
			MissingLifeTime -= SliceTime;
		}
	}
}
