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

#include "Event/EventView.h"

#include "NansTimelineSystemCore/Public/Event.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerDecorator.h"

void UNEventView::Init(TSharedPtr<NEventInterface> _Event)
{
	Event = _Event;
	Event->OnStart().AddUObject(this, &UNEventView::WhenOnStart);
}

bool UNEventView::IsExpired() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->IsExpired();
}

const float UNEventView::GetLocalTime() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->GetLocalTime();
}

const float UNEventView::GetStartedAt() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->GetStartedAt();
}

float UNEventView::GetDuration() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->GetDuration();
}

float UNEventView::GetDelay() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->GetDelay();
}

const FName UNEventView::GetEventLabel() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->GetEventLabel();
}

const FString UNEventView::GetUID() const
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->GetUID();
}

FNEventDelegate& UNEventView::OnStart()
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event->OnStart();
}

void UNEventView::SetEventLabel(FName _EventLabel)
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	Event->SetEventLabel(_EventLabel);
}

TSharedPtr<NEventInterface> UNEventView::GetEvent()
{
	checkf(Event.IsValid(), TEXT("An NEvent object is madatory! Please use Init before anything else!"));
	return Event;
}

void UNEventView::WhenOnStart(NEventInterface* StartedEvent, const float& StartTime)
{
	OnStartEvent(this, StartTime);
}

void UNEventView::BeginDestroy()
{
	if (Event.IsValid())
	{
		Event->OnStart().RemoveAll(this);
		// cause it is only a view object,
		// it will not altered object by calling PreDelete or clear.
		Event.Reset();
	}
	Super::BeginDestroy();
}
