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

void UNRealLifeTimelineManager::Init()
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNRealLifeTimelineManager need a world to live"));
}

void UNRealLifeTimelineManager::Tick(float DeltaTime)
{
	TotalLifeTime += DeltaTime;
	if (TotalLifeTime - LastTimeTick >= GetTickInterval())
	{
		LastTimeTick = TotalLifeTime;
		TimerTick();
	}
}

bool UNRealLifeTimelineManager::IsTickable() const
{
	return State != ENTimelineTimerState::Played ? false : true;
}

UWorld* UNRealLifeTimelineManager::GetTickableGameObjectWorld() const
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNRealLifeTimelineManager need a world to live"));
	return GetWorld();
}
