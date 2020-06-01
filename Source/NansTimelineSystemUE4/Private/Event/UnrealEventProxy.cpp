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

#include "Event/UnrealEventProxy.h"

#include "Event/EventDecorator.h"

bool NUnrealEventProxy::IsExpired() const
{
	return Event.IsExpired();
}

const float NUnrealEventProxy::GetLocalTime() const
{
	return Event.GetLocalTime();
}

const float NUnrealEventProxy::GetStartedAt() const
{
	return Event.GetStartedAt();
}

float NUnrealEventProxy::GetDuration() const
{
	return Event.GetDuration();
}

void NUnrealEventProxy::Start(float StartTime)
{
	Event.Start(StartTime);
}

void NUnrealEventProxy::NotifyAddTime(float NewTime)
{
	Event.NotifyAddTime(NewTime);
}

float NUnrealEventProxy::GetDelay() const
{
	return Event.GetDelay();
}

const FName NUnrealEventProxy::GetEventLabel() const
{
	return Event.GetEventLabel();
}

const FString NUnrealEventProxy::GetUID() const
{
	return Event.GetUID();
}

void NUnrealEventProxy::SetLocalTime(float _LocalTime)
{
	Event.SetLocalTime(_LocalTime);
}

void NUnrealEventProxy::SetStartedAt(float _StartedAt)
{
	Event.SetStartedAt(_StartedAt);
}

void NUnrealEventProxy::SetDuration(float _Duration)
{
	Event.SetDuration(_Duration);
}

void NUnrealEventProxy::SetDelay(float _Delay)
{
	Event.SetDelay(_Delay);
}

void NUnrealEventProxy::SetEventLabel(FName _EventLabel)
{
	Event.SetEventLabel(_EventLabel);
}

void NUnrealEventProxy::Clear()
{
	Event.Clear();
}

UNEventDecorator& NUnrealEventProxy::GetUnrealObject()
{
	return Event;
}
