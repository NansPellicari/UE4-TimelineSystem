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

class NANSTIMELINESYSTEMCORE_API NEventInterface
{
public:
	virtual bool IsExpired() const = 0;
	virtual const float GetLocalTime() const = 0;
	virtual const float GetStartedAt() const = 0;
	virtual float GetDuration() const = 0;
	virtual float GetDelay() const = 0;
	virtual const FString GetUID() const = 0;
	virtual const FName GetEventLabel() const = 0;
	virtual void SetLocalTime(float _LocalTime) = 0;
	virtual void SetStartedAt(float _StartedAt) = 0;
	virtual void SetDuration(float _Duration) = 0;
	virtual void SetDelay(float _Delay) = 0;
	virtual void SetEventLabel(FName _EventLabel) = 0;
	virtual void Start(float StartTime) = 0;
	virtual void NotifyAddTime(float NewTime) = 0;
	virtual void Clear() = 0;
};
