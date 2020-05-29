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
#include "Event//UnrealEventProxy.h"
#include "NansTimelineSystemCore/Public/EventInterface.h"
#include "NansTimelineSystemCore/Public/TimelineInterface.h"
#include "TimelineDecorator.h"

/**
 *  This class is a pass-through to allows an NUnrealTimelineProxy (a derived UObject)
 * to be passed on the core system using TSharedPtr, and it manages NUnrealEventProxy
 * attachment .
 */
class NANSTIMELINESYSTEMUE4_API NUnrealTimelineProxy : public NTimelineInterface
{
public:
	UNTimelineDecorator& Timeline;

	NUnrealTimelineProxy(UNTimelineDecorator& _Timeline) : Timeline(_Timeline) {}

	virtual bool Attached(TSharedPtr<NEventInterface> Event) override;
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) override;
	virtual void SetTickInterval(float _TickInterval) override;
	virtual void SetCurrentTime(float _CurrentTime) override;
	virtual float GetCurrentTime() const override;
	virtual void SetLabel(FName _Label) override;
	virtual FName GetLabel() const override;
	virtual void Clear() override;
	virtual void NotifyTick() override;
};
