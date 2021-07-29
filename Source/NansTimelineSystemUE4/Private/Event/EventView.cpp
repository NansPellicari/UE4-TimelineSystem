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

#include "Event.h"

#define CHECK_EVENT checkf(Event.IsValid(), TEXT("An NEvent object is mandatory! Please use Init before anything else!"))

void UNEventView::Init(TSharedPtr<INEventInterface> _Event)
{
	Event = _Event;
	Event->OnStart().AddUObject(this, &UNEventView::WhenOnStart);
}

bool UNEventView::IsExpired() const
{
	CHECK_EVENT;
	return Event->IsExpired();
}

float UNEventView::GetLocalTime() const
{
	CHECK_EVENT;
	return Event->GetLocalTime();
}

float UNEventView::GetStartedAt() const
{
	CHECK_EVENT;
	return Event->GetStartedAt();
}

float UNEventView::GetDuration() const
{
	CHECK_EVENT;
	return Event->GetDuration();
}

float UNEventView::GetDelay() const
{
	CHECK_EVENT;
	return Event->GetDelay();
}

FName UNEventView::GetEventLabel() const
{
	CHECK_EVENT;
	return Event->GetEventLabel();
}

FString UNEventView::GetUID() const
{
	CHECK_EVENT;
	return Event->GetUID();
}

float UNEventView::GetAttachedTime() const
{
	CHECK_EVENT;
	return Event->GetAttachedTime();
}

bool UNEventView::IsAttachable() const
{
	CHECK_EVENT;
	return Event->IsAttachable();
}

float UNEventView::GetExpiredTime() const
{
	CHECK_EVENT;
	return Event->GetExpiredTime();
}

FNEventDelegate& UNEventView::OnStart()
{
	CHECK_EVENT;
	return Event->OnStart();
}

void UNEventView::SetEventLabel(const FName& InEventLabel)
{
	CHECK_EVENT;
	Event->SetEventLabel(InEventLabel);
}

TSharedPtr<INEventInterface> UNEventView::GetEvent()
{
	CHECK_EVENT;
	return Event;
}

void UNEventView::WhenOnStart(INEventInterface* StartedEvent, const float& StartTime)
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
