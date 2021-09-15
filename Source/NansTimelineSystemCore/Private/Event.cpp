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

FNEvent::FNEvent()
{
	if (UId.IsEmpty())
	{
		UId = FGuid::NewGuid().ToString();
	}
}

FNEvent::FNEvent(const FName& InLabel, const FString& InUId)
{
	Label = InLabel;
	if (!InUId.IsEmpty())
	{
		UId = InUId;
	}
	else
	{
		UId = FGuid::NewGuid().ToString();
	}
}

bool FNEvent::IsExpired() const
{
	return (!bActivated && GetStartedAt() > -1.f) || (GetDuration() > 0 && GetLocalTime() >= GetDuration());
};

float FNEvent::GetLocalTime() const
{
	return LocalTime;
}

float FNEvent::GetAttachedTime() const
{
	return AttachedTime;
}

void FNEvent::SetAttachedTime(const float& InLocalTime)
{
	AttachedTime = InLocalTime;
}

void FNEvent::SetAttachable(const bool& bInIsAttachable)
{
	bIsAttachable = bInIsAttachable;
}

bool FNEvent::IsAttachable() const
{
	return bIsAttachable;
}

float FNEvent::GetStartedAt() const
{
	return StartedAt;
}

float FNEvent::GetDuration() const
{
	return Duration;
}

float FNEvent::GetDelay() const
{
	return Delay;
}

FName FNEvent::GetEventLabel() const
{
	return Label;
}

FString FNEvent::GetUID() const
{
	return UId;
}

float FNEvent::GetExpiredTime() const
{
	return ExpiredTime;
}

void FNEvent::SetDuration(const float& InDuration)
{
	Duration = InDuration;
}

void FNEvent::SetDelay(const float& InDelay)
{
	Delay = InDelay;
}

void FNEvent::SetEventLabel(const FName& InEventLabel)
{
	Label = InEventLabel;
}

void FNEvent::SetExpiredTime(const float& InLocalTime)
{
	ExpiredTime = InLocalTime;
}

void FNEvent::Start(const float& StartTime)
{
	StartedAt = StartTime;
	bActivated = true;
}

void FNEvent::Stop()
{
	bActivated = false;
}

void FNEvent::AddTime(const float& NewTime)
{
	LocalTime += NewTime;
}

void FNEvent::Clear()
{
	Label = NAME_None;
	LocalTime = 0.f;
	StartedAt = -1.f;
	Duration = 0.f;
	Delay = 0.f;
}

void FNEvent::Archive(FArchive& Ar)
{
	Ar << UId;
	Ar << AttachedTime;
	Ar << Delay;
	Ar << Duration;
	Ar << LocalTime;
	Ar << StartedAt;
	Ar << Label;
	Ar << ExpiredTime;
	Ar << bActivated;
}
