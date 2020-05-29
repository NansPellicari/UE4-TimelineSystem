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

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NansTimelineSystemCore/Public/TimelineManager.h"
#include "TimerManager.h"

/**
 * This class is used for tests only
 */
class NTimelineManagerFake : public NTimelineManager
{
public:
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	float Counter = 0;

	NTimelineManagerFake()
	{
		TimerDelegate = FTimerDelegate::CreateRaw(this, &NTimelineManagerFake::TimerTick);
	}

	virtual void onNotifyTimelineTickBefore() override
	{
		Counter++;
		UE_LOG(LogTemp, Display, TEXT("%s - tick %f"), ANSI_TO_TCHAR(__FUNCTION__), Counter);
	}

	virtual void Clear() override
	{
		TimerDelegate.Unbind();
		TimerHandle.Invalidate();
	}
};
