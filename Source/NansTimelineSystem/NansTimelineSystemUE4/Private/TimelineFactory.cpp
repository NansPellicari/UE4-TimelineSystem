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

#include "TimelineFactory.h"

#include "Manager/TimelineManagerBase.h"
#include "NansTimelineSystemCore/Public/Timeline.h"

UNTimelineManagerBase* UTimelineFactory::CreateNewTimeline(
	UObject* WorldContextObject, TSubclassOf<UNTimelineManagerBase> Class, FName Name)
{
	UNTimelineManagerBase* Object = UNTimelineManagerBase::CreateObject<UNTimelineManagerBase>(WorldContextObject, Class);
	if (Object->GetTimeline().IsValid())
	{
		Object->GetTimeline()->SetLabel(Name);
	}
	return Object;
}
