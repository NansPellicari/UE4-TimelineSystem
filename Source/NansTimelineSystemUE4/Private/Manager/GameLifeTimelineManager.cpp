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

#include "Manager/GameLifeTimelineManager.h"

#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TimerManager.h"

UNGameLifeTimelineManager::UNGameLifeTimelineManager() {}

void UNGameLifeTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Super::Init(InTickInterval, InLabel);
	TimerDelegate = FTimerDelegate::CreateUObject(this, &UNGameLifeTimelineManager::TimerTick);
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, TimerDelegate, GetTimeline()->GetTickInterval(), true);
}

void UNGameLifeTimelineManager::Clear()
{
	if (IsValid(GetWorld()))
	{
		FTimerManager& TimerManager = GetWorld()->GetTimerManager();
		TimerManager.ClearTimer(TimerHandle);
	}

	TimerDelegate.Unbind();
	TimerHandle.Invalidate();
	UNTimelineManagerDecorator::Clear();
}
