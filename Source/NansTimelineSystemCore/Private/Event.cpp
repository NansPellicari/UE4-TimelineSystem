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

#include "NansTimelineSystemCore/Public/Event.h"

NEvent::NEvent()
{
	if (UId.IsEmpty())
	{
		UId = FGuid::NewGuid().ToString();
	}
}

NEvent::NEvent(FName _Label, FString _UId)
{
	Label = _Label;
	if (!_UId.IsEmpty())
	{
		UId = _UId;
	}
	else
	{
		UId = FGuid::NewGuid().ToString();
	}
}

NEvent::NEvent(FNEventSave Record)
{
	UId = Record.UID;
	Delay = Record.Delay;
	Duration = Record.Duration;
	LocalTime = Record.LocalTime;
	StartedAt = Record.StartedAt;
	Label = Record.Label;
	bActivated = Record.ExpiredTime <= 0.f;
}

bool NEvent::IsExpired() const
{
	return !bActivated || (GetDuration() > 0 && GetLocalTime() >= GetDuration());
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
	return UId;
}

void NEvent::SetUID(FString _UId)
{
	UId = _UId;
}

void NEvent::SetLocalTime(float _LocalTime)
{
	LocalTime = _LocalTime;
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
	bActivated = true;
	EventStart.Broadcast(this, StartedAt);
}

void NEvent::Stop()
{
	bActivated = false;
}

void NEvent::NotifyAddTime(float NewTime)
{
	LocalTime += NewTime;
}

FNEventDelegate& NEvent::OnStart()
{
	return EventStart;
}

void NEvent::Clear()
{
	Label = NAME_None;
	LocalTime = 0.f;
	StartedAt = -1.f;
	Duration = 0.f;
	Delay = 0.f;
}

void NEvent::PreDelete()
{
	Clear();
}
