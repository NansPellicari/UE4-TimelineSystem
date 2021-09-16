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
