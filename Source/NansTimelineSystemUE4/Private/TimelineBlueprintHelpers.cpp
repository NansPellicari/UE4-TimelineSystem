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

#include "Event/TimelineEventAdapter.h"
#include "Manager/TimelineManagerBaseAdapter.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "TimelineGameInstance.h"

UNTimelineManagerBaseAdapter* UNTimelineBlueprintHelpers::CreateNewTimeline(
	UObject* WorldContextObject, TSubclassOf<UNTimelineManagerBaseAdapter> Class, FName Name)
{
	UNTimelineManagerBaseAdapter* Object =
		UNTimelineManagerBaseAdapter::CreateObject<UNTimelineManagerBaseAdapter>(WorldContextObject, Class, Name);
	return Object;
}

void UNTimelineBlueprintHelpers::CreateAndAttachedEvent(UObject* WorldContextObject, FConfiguredTimeline Timeline)
{
	UNTimelineGameInstance* GI = Cast<UNTimelineGameInstance>(WorldContextObject->GetWorld()->GetGameInstance());
	checkf(GI != nullptr, TEXT("Game instance should derived from UNTimelineGameInstance class."));
	UNTimelineManagerBaseAdapter* TimelineObj = GI->GetTimeline(Timeline.Name);
	checkf(TimelineObj != nullptr, TEXT("A problem occured in timeline configuration."));

	UE_LOG(LogTemp,
		Display,
		TEXT("%s classname %s objectpath %s"),
		ANSI_TO_TCHAR(__FUNCTION__),
		*Timeline.TimelineClass->GetFullName(),
		*TimelineObj->GetFullName());
}
