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

#include "TimelineBlueprintHelpers.h"

#include "Engine.h"
#include "TimelineGameSubsystem.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Manager/TimelineManagerDecorator.h"

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
