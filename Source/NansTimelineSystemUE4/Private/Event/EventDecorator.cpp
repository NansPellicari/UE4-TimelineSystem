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

#include "Event/EventDecorator.h"

#include "NansTimelineSystemCore/Public/Event.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerDecorator.h"

void UNEventDecorator::Init(FName _Label)
{
	Event = MakeShareable(new NEvent(_Label));
	OnInit();
}

bool UNEventDecorator::IsExpired() const
{
	if (!Event.IsValid()) return true;
	return Event->IsExpired();
}

const float UNEventDecorator::GetLocalTime() const
{
	if (!Event.IsValid()) return -1.f;
	return Event->GetLocalTime();
}

const float UNEventDecorator::GetStartedAt() const
{
	if (!Event.IsValid()) return -1.f;
	return Event->GetStartedAt();
}

float UNEventDecorator::GetDuration() const
{
	if (!Event.IsValid()) return -1.f;
	return Event->GetDuration();
}

void UNEventDecorator::Start(float StartTime)
{
	if (!Event.IsValid()) return;
	Event->Start(StartTime);
}

void UNEventDecorator::Stop()
{
	if (!Event.IsValid()) return;
	Event->Stop();
}

void UNEventDecorator::NotifyAddTime(float NewTime)
{
	if (!Event.IsValid()) return;
	Event->NotifyAddTime(NewTime);
}

float UNEventDecorator::GetDelay() const
{
	if (!Event.IsValid()) return -1.f;
	return Event->GetDelay();
}

const FName UNEventDecorator::GetEventLabel() const
{
	if (!Event.IsValid()) return Label;
	return Event->GetEventLabel();
}

const FString UNEventDecorator::GetUID() const
{
	if (!Event.IsValid()) return FString("");
	return Event->GetUID();
}

void UNEventDecorator::SetUID(FString _UId)
{
	if (!Event.IsValid()) return;
	Event->SetUID(_UId);
}

void UNEventDecorator::SetLocalTime(float _LocalTime)
{
	if (!Event.IsValid()) return;
	Event->SetLocalTime(_LocalTime);
}

void UNEventDecorator::SetDuration(float _Duration)
{
	if (!Event.IsValid()) return;
	Event->SetDuration(_Duration);
}

void UNEventDecorator::SetDelay(float _Delay)
{
	if (!Event.IsValid()) return;
	Event->SetDelay(_Delay);
}

void UNEventDecorator::SetEventLabel(FName _EventLabel)
{
	if (!Event.IsValid()) return;
	Event->SetEventLabel(_EventLabel);
}

TSharedPtr<NEventInterface> UNEventDecorator::GetEvent() const
{
	return Event;
}

void UNEventDecorator::BeginDestroy()
{
	if (Event.IsValid())
	{
		Event->PreDelete();
		Event.Reset();
	}
	Super::BeginDestroy();
}

void UNEventDecorator::Clear()
{
	Event->Clear();
}

FNEventDelegate& UNEventDecorator::OnStart()
{
	return Event->OnStart();
}

void UNEventDecorator::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (Event.IsValid())
	{
		Event->Archive(Ar);
	}
}
