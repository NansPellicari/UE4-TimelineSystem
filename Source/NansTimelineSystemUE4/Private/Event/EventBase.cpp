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

#include "Event/EventBase.h"

#define CHECK_EVENT_V() if (!ensureMsgf(Event.IsValid(), TEXT("An NEvent object is mandatory! Please use Init before anything else!"))) return;
#define CHECK_EVENT(ReturnValue) if (!ensureMsgf(Event.IsValid(), TEXT("An NEvent object is mandatory! Please use Init before anything else!"))) return ReturnValue;

void UNEventBase::Init(const TSharedPtr<INEvent>& InEvent, const float& InLocalTime, UWorld* InWorld,
	APlayerController* InPlayer)
{
	Event = InEvent;
	OnInit(InLocalTime, InWorld, InPlayer);
}

bool UNEventBase::IsExpired() const
{
	CHECK_EVENT(false);
	return Event->IsExpired();
}

float UNEventBase::GetLocalTime() const
{
	CHECK_EVENT(0);
	return Event->GetLocalTime();
}

float UNEventBase::GetStartedAt() const
{
	CHECK_EVENT(0);
	return Event->GetStartedAt();
}

float UNEventBase::GetDuration() const
{
	CHECK_EVENT(0);
	return Event->GetDuration();
}

float UNEventBase::GetDelay() const
{
	CHECK_EVENT(0);
	return Event->GetDelay();
}

FName UNEventBase::GetEventLabel() const
{
	CHECK_EVENT(NAME_None);
	return Event->GetEventLabel();
}

FString UNEventBase::GetUID() const
{
	CHECK_EVENT(TEXT(""));
	return Event->GetUID();
}

float UNEventBase::GetAttachedTime() const
{
	CHECK_EVENT(0);
	return Event->GetAttachedTime();
}

bool UNEventBase::IsAttachable() const
{
	CHECK_EVENT(false);
	return Event->IsAttachable();
}

float UNEventBase::GetExpiredTime() const
{
	CHECK_EVENT(0);
	return Event->GetExpiredTime();
}

void UNEventBase::Stop()
{
	CHECK_EVENT_V();
	return Event->Stop();
}

void UNEventBase::SetEventLabel(const FName& InEventLabel)
{
	CHECK_EVENT_V();
	Event->SetEventLabel(InEventLabel);
}

TSharedPtr<INEvent> UNEventBase::GetEvent()
{
	CHECK_EVENT(nullptr);
	return Event;
}

#if WITH_EDITOR
FColor UNEventBase::GetDebugColor_Implementation() const
{
	return FColor(255, 140, 255, 255);
}

FString UNEventBase::GetDebugTooltipText_Implementation() const
{
	FString TooltipBuilder;
	TooltipBuilder += FString::Format(TEXT("Name: {0}"), {GetEventLabel().ToString()});
	if (IsExpired())
	{
		TooltipBuilder += TEXT(" (expired)");
	}
	TooltipBuilder += FString::Format(TEXT("\nAttached at: {0}"), {GetAttachedTime()});
	TooltipBuilder += FString::Format(TEXT("\nStarted at: {0}"), {GetStartedAt()});
	TooltipBuilder += FString::Format(TEXT("\nDuration: {0}"), {GetDuration()});
	TooltipBuilder += FString::Format(TEXT("\nDelay: {0}"), {GetDelay()});
	TooltipBuilder += FString::Format(TEXT("\nUId: {0}"), {GetUID()});
	return TooltipBuilder;
}
#endif

void UNEventBase::BeginDestroy()
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
bool UNEventBaseBlueprint::SupportedByDefaultBlueprintFactory() const
{
	return false;
}

/** Returns the most base UNEventBase blueprint for a given blueprint (if it is inherited from another event blueprint, returning null if only native / non-event BP classes are it's parent) */
UNEventBaseBlueprint* UNEventBaseBlueprint::FindRootEventBlueprint(UNEventBaseBlueprint* DerivedBlueprint)
{
	UNEventBaseBlueprint* ParentBP = nullptr;

	// Determine if there is a UNEventBase blueprint in the ancestry of this class
	for (UClass* ParentClass = DerivedBlueprint->ParentClass; ParentClass != UObject::StaticClass();
		 ParentClass = ParentClass->GetSuperClass())
	{
		if (UNEventBaseBlueprint* TestBP = Cast<UNEventBaseBlueprint>(ParentClass->ClassGeneratedBy))
		{
			ParentBP = TestBP;
		}
	}

	return ParentBP;
}

#endif
