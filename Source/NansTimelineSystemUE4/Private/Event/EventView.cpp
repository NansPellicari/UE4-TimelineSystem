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

#define CHECK_EVENT_V() if (!ensureMsgf(Event.IsValid(), TEXT("An NEvent object is mandatory! Please use Init before anything else!"))) return;
#define CHECK_EVENT(ReturnValue) if (!ensureMsgf(Event.IsValid(), TEXT("An NEvent object is mandatory! Please use Init before anything else!"))) return ReturnValue;

void UNEventView::Init(const TSharedPtr<INEvent>& InEvent)
{
	Event = InEvent;
	OnInit();
}

bool UNEventView::IsExpired() const
{
	CHECK_EVENT(false);
	return Event->IsExpired();
}

float UNEventView::GetLocalTime() const
{
	CHECK_EVENT(0);
	return Event->GetLocalTime();
}

float UNEventView::GetStartedAt() const
{
	CHECK_EVENT(0);
	return Event->GetStartedAt();
}

float UNEventView::GetDuration() const
{
	CHECK_EVENT(0);
	return Event->GetDuration();
}

float UNEventView::GetDelay() const
{
	CHECK_EVENT(0);
	return Event->GetDelay();
}

FName UNEventView::GetEventLabel() const
{
	CHECK_EVENT(NAME_None);
	return Event->GetEventLabel();
}

FString UNEventView::GetUID() const
{
	CHECK_EVENT(TEXT(""));
	return Event->GetUID();
}

float UNEventView::GetAttachedTime() const
{
	CHECK_EVENT(0);
	return Event->GetAttachedTime();
}

bool UNEventView::IsAttachable() const
{
	CHECK_EVENT(false);
	return Event->IsAttachable();
}

float UNEventView::GetExpiredTime() const
{
	CHECK_EVENT(0);
	return Event->GetExpiredTime();
}

void UNEventView::Stop()
{
	CHECK_EVENT_V();
	return Event->Stop();
}

void UNEventView::SetEventLabel(const FName& InEventLabel)
{
	CHECK_EVENT_V();
	Event->SetEventLabel(InEventLabel);
}

TSharedPtr<INEvent> UNEventView::GetEvent()
{
	CHECK_EVENT(nullptr);
	return Event;
}

void UNEventView::BeginDestroy()
{
	if (Event.IsValid())
	{
		// cause it is only a view object,
		// it will not altered object by calling PreDelete or clear.
		Event.Reset();
	}
	Super::BeginDestroy();
}

#if WITH_EDITOR
bool UNEventViewBlueprint::SupportedByDefaultBlueprintFactory() const
{
	return false;
}

/** Returns the most base UNEventView blueprint for a given blueprint (if it is inherited from another event blueprint, returning null if only native / non-event BP classes are it's parent) */
UNEventViewBlueprint* UNEventViewBlueprint::FindRootEventViewBlueprint(UNEventViewBlueprint* DerivedBlueprint)
{
	UNEventViewBlueprint* ParentBP = nullptr;

	// Determine if there is a UNEventView blueprint in the ancestry of this class
	for (UClass* ParentClass = DerivedBlueprint->ParentClass; ParentClass != UObject::StaticClass();
		 ParentClass = ParentClass->GetSuperClass())
	{
		if (UNEventViewBlueprint* TestBP = Cast<UNEventViewBlueprint>(ParentClass->ClassGeneratedBy))
		{
			ParentBP = TestBP;
		}
	}

	return ParentBP;
}

#endif
