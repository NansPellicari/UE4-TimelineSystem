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

#include "Event/TimelineEventDecorator.h"

#include "NansTimelineSystemCore/Public/TimelineEventBase.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerDecorator.h"

bool UNTimelineEventDecorator::IsExpired() const
{
	if (!Event.IsValid()) return true;
	return Event->IsExpired();
}

const float UNTimelineEventDecorator::GetLocalTime() const
{
	if (!Event.IsValid()) return LocalTime;
	return Event->GetLocalTime();
}

const float UNTimelineEventDecorator::GetStartedAt() const
{
	if (!Event.IsValid()) return StartedAt;
	return Event->GetStartedAt();
}

float UNTimelineEventDecorator::GetDuration() const
{
	if (!Event.IsValid()) return Duration;
	return Event->GetDuration();
}

void UNTimelineEventDecorator::Start(float StartTime)
{
	if (!Event.IsValid()) return;
	Event->Start(StartTime);
}

void UNTimelineEventDecorator::NotifyAddTime(float NewTime)
{
	if (!Event.IsValid()) return;
	Event->NotifyAddTime(NewTime);
}

float UNTimelineEventDecorator::GetDelay() const
{
	if (!Event.IsValid()) return Delay;
	return Event->GetDelay();
}

const FName UNTimelineEventDecorator::GetEventLabel() const
{
	if (!Event.IsValid()) return Label;
	return Event->GetEventLabel();
}

const FString UNTimelineEventDecorator::GetUID() const
{
	return Event->GetUID();
}

void UNTimelineEventDecorator::SetLocalTime(float _LocalTime)
{
	Event->SetLocalTime(_LocalTime);
}

void UNTimelineEventDecorator::SetStartedAt(float _StartedAt)
{
	Event->SetStartedAt(_StartedAt);
}

void UNTimelineEventDecorator::SetDuration(float _Duration)
{
	Event->SetDuration(_Duration);
}

void UNTimelineEventDecorator::SetDelay(float _Delay)
{
	Event->SetDelay(_Delay);
}

void UNTimelineEventDecorator::SetEventLabel(FName _EventLabel)
{
	Event->SetEventLabel(_EventLabel);
}

TSharedPtr<NTimelineEventInterface> UNTimelineEventDecorator::GetEvent() const
{
	return Event;
}

void UNTimelineEventDecorator::Init(FName _Label)
{
	Event = MakeShareable(new NTimelineEventBase(_Label));
}
void UNTimelineEventDecorator::BeginDestroy()
{
	Super::BeginDestroy();
	Event.Reset();
}

void UNTimelineEventDecorator::Clear()
{
	Event->Clear();
}

void UNTimelineEventDecorator::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (Ar.IsSaving() && Event.IsValid())
	{
		Label = Event->GetEventLabel();
		LocalTime = Event->GetLocalTime();
		StartedAt = Event->GetStartedAt();
		Duration = Event->GetDuration();
		Delay = Event->GetDelay();
	}

	Ar << Label;
	Ar << LocalTime;
	Ar << StartedAt;
	Ar << Duration;
	Ar << Delay;

	if (Ar.IsLoading() && !Event.IsValid())
	{
		Init(Label);
	}

	if (Event.IsValid())
	{
		Event->SetEventLabel(Label);
		Event->SetLocalTime(LocalTime);
		Event->SetStartedAt(StartedAt);
		Event->SetDuration(Duration);
		Event->SetDelay(Delay);
	}
}
