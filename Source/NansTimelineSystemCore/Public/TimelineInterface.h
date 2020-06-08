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
#include "EventInterface.h"

DECLARE_MULTICAST_DELEGATE_ThreeParams(FEventDelegate, TSharedPtr<NEventInterface>, const float&, const int32&);

class NANSTIMELINESYSTEMCORE_API NTimelineInterface
{
public:
	virtual bool Attached(TSharedPtr<NEventInterface> Event) = 0;
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) = 0;
	virtual void SetTickInterval(float _TickInterval) = 0;
	virtual void SetCurrentTime(float _CurrentTime) = 0;
	virtual float GetCurrentTime() const = 0;
	virtual void SetLabel(FName _Label) = 0;
	virtual FName GetLabel() const = 0;
	virtual void Clear() = 0;
	virtual void NotifyTick() = 0;
	virtual FEventDelegate& OnEventExpired() = 0;
};
