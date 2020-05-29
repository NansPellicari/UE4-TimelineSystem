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

#include "Event.h"

bool NEvent::IsExpired() const
{
	return GetDuration() > 0 && GetLocalTime() >= GetDuration();
};

const float NEvent::GetLocalTime() const
{
	return LocalTime;
}

const float NEvent::GetStartedAt() const
{
	return StartedAt;
}

float NEvent::GetDuration() const
{
	return Duration;
}
float NEvent::GetDelay() const
{
	return Delay;
}

const FName NEvent::GetEventLabel() const
{
	return Label;
}

const FString NEvent::GetUID() const
{
	return Id;
}

void NEvent::SetLocalTime(float _LocalTime)
{
	LocalTime = _LocalTime;
}

void NEvent::SetStartedAt(float _StartedAt)
{
	StartedAt = _StartedAt;
}

void NEvent::SetDuration(float _Duration)
{
	Duration = _Duration;
}

void NEvent::SetDelay(float _Delay)
{
	Delay = _Delay;
}

void NEvent::SetEventLabel(FName _EventLabel)
{
	Label = _EventLabel;
}

void NEvent::Start(float StartTime)
{
	StartedAt = StartTime;
}

void NEvent::NotifyAddTime(float NewTime)
{
	LocalTime += NewTime;
}

void NEvent::Clear()
{
	Label = NAME_None;
	LocalTime = 0.f;
	StartedAt = -1.f;
	Duration = 0.f;
	Delay = 0.f;
}
