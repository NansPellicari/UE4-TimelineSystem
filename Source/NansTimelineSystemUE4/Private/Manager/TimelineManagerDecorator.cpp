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

#include "Manager/TimelineManagerDecorator.h"

#include "Event/EventBase.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "NansTimelineSystemUE4.h"

FString EnumToString(const ENTimelineEvent& Value)
{
	static const UEnum* TypeEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("ENTimelineEvent"));
	return TypeEnum->GetNameStringByIndex(static_cast<int32>(Value));
}

UNTimelineManagerDecorator::UNTimelineManagerDecorator() : FNTimelineManager() {}

void UNTimelineManagerDecorator::Init(const float& InTickInterval, const FName& InLabel)
{
	ensureMsgf(GetWorld() != nullptr, TEXT("A UNTimelineManagerDecorator need a world to live"));
	FNTimelineManager::Init(InTickInterval, InLabel);

	OnEventChanged().AddUObject(this, &UNTimelineManagerDecorator::OnEventChangedDelegate);
}

void UNTimelineManagerDecorator::Pause()
{
	FNTimelineManager::Pause();
}

void UNTimelineManagerDecorator::Play()
{
	FNTimelineManager::Play();
}

void UNTimelineManagerDecorator::Stop()
{
	FNTimelineManager::Stop();
}

struct FParamsEventChanged
{
	float InLocalTime = -1.f;
	UWorld* InWorld = nullptr;
	APlayerController* InPlayer = nullptr;
};

void UNTimelineManagerDecorator::OnEventChangedDelegate(TSharedPtr<INEvent> Event,
	const ENTimelineEvent& EventName, const float& LocalTime, const int32& Index)
{
	UNEventBase* EventBase = EventBases.FindRef(Event->GetUID());
	if (!ensure(IsValid(EventBase)))
	{
		return;
	}

	OnBPEventChanged(EventBase, LocalTime);

	FString FuncName = FString::Printf(TEXT("On%s"), *EnumToString(EventName));
	UFunction* Func = EventBase->FindFunction(FName(FuncName));

	if (Func != nullptr)
	{
		bool bSupported = true;
		FParamsEventChanged Param;
		Param.InLocalTime = LocalTime;
		Param.InWorld = GetWorldChecked(bSupported);
		Param.InPlayer = Param.InWorld->GetFirstPlayerController();

		UE_DEBUG_LOG(
			LogTimelineSystem, Display, TEXT("FuncName \"%s\" for event \"%s\" will be called at %f secs"), *FuncName,
			*EventBase->GetEventLabel().ToString(), LocalTime
		);
		EventBase->ProcessEvent(Func, &Param);
	}
	else
	{
		UE_DEBUG_LOG(
			LogTimelineSystem, Warning, TEXT("FuncName \"%s\" for event \"%s\" not exists"), *FuncName,
			*EventBase->GetEventLabel().ToString()
		);
	}

	if (EventName == ENTimelineEvent::Expired)
	{
		ExpiredEventBases.Add(Event->GetUID(), EventBase);
		EventBases.Remove(Event->GetUID());
	}
}

TArray<UNEventBase*> UNTimelineManagerDecorator::GetEvents() const
{
	TArray<UNEventBase*> EventRecords;
	EventBases.GenerateValueArray(EventRecords);
	return EventRecords;
}

TArray<UNEventBase*> UNTimelineManagerDecorator::GetExpiredEvents() const
{
	TArray<UNEventBase*> EventRecords;
	ExpiredEventBases.GenerateValueArray(EventRecords);
	return EventRecords;
}

UNEventBase* UNTimelineManagerDecorator::GetEvent(const FString& InUID) const
{
	return EventBases.FindRef(InUID);
}

UNEventBase* UNTimelineManagerDecorator::GetExpiredEvent(const FString& InUID) const
{
	return ExpiredEventBases.FindRef(InUID);
}

float UNTimelineManagerDecorator::GetCurrentTime() const
{
	check(GetTimeline().IsValid());
	return GetTimeline()->GetCurrentTime();
}

FName UNTimelineManagerDecorator::GetLabel() const
{
	check(GetTimeline().IsValid());
	return GetTimeline()->GetLabel();
}

void UNTimelineManagerDecorator::SetLabel(const FName& Name)
{
	check(GetTimeline().IsValid());
	GetTimeline()->SetLabel(Name);
}

UNEventBase* UNTimelineManagerDecorator::CreateAndAddNewEvent(FName InName, TSubclassOf<UNEventBase> InClass,
	float InDuration, float InDelay)
{
	UClass* ChildClass;
	if (InClass)
	{
		ChildClass = *InClass;
	}
	else
	{
		ChildClass = UNEventBase::StaticClass();
	}

	const TSharedPtr<INEvent> Object = CreateNewEvent(InName, InDuration, InDelay);
	if (!Object.IsValid()) return nullptr;

	UNEventBase* Event = NewObject<UNEventBase>(this, ChildClass);
	Event->Init(Object, GetCurrentTime(), GetWorld(), GetWorld()->GetFirstPlayerController());
	EventBases.Add(Object->GetUID(), Event);

	GetTimeline()->Attached(Object);
	return Event;
}

void UNTimelineManagerDecorator::Clear()
{
	for (const TTuple<FString, UNEventBase*>& Event : EventBases)
	{
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (IsValid(GetWorld()) && IsValid(PlayerController))
		{
			Event.Value->OnCleared(GetCurrentTime(), GetWorld(), PlayerController);
		}
	}
	EventBases.Empty();
	ExpiredEventBases.Empty();
	FNTimelineManager::Clear();
}

void UNTimelineManagerDecorator::Serialize(FArchive& Ar)
{
	// Thanks to the UE4 serializing system, this will serialize all uproperty with "SaveGame"
	Super::Serialize(Ar);
	Archive(Ar);

	int32 NumEntries = 0;
	int32 NumExpiredEntries = 0;

	if (Ar.IsSaving())
	{
		NumEntries = EventBases.Num();
		NumExpiredEntries = ExpiredEventBases.Num();
	}

	Ar << NumEntries;
	Ar << NumExpiredEntries;

	if (Ar.IsSaving() && NumEntries > 0)
	{
		for (TTuple<FString, UNEventBase*> Pair : EventBases)
		{
			Ar << Pair.Key;
			FString PathClass = Pair.Value->GetClass()->GetPathName();
			Ar << PathClass;
			Pair.Value->Serialize(Ar);
		}
	}

	if (Ar.IsSaving() && NumExpiredEntries > 0)
	{
		for (TTuple<FString, UNEventBase*> Pair : ExpiredEventBases)
		{
			Ar << Pair.Key;
			FString PathClass = Pair.Value->GetClass()->GetPathName();
			Ar << PathClass;
			Pair.Value->Serialize(Ar);
		}
	}

	if (Ar.IsLoading() && NumEntries > 0)
	{
		for (int32 I = 0; I < NumEntries; I ++)
		{
			FString Id, PathClass;
			Ar << Id;
			Ar << PathClass;

			TSharedPtr<INEvent> Event = Timeline->GetEvent(Id);

			if (ensureMsgf(
				Event.IsValid(), TEXT("Event with Uid (\"%s\") can't be retrieved during serialization."), *Id
			))
			{
				UClass* Class = ConstructorHelpersInternal::FindOrLoadClass(PathClass, UNEventBase::StaticClass());
				UNEventBase* Object = NewObject<UNEventBase>(this, Class);
				Object->Serialize(Ar);
				Object->Init(Event, GetCurrentTime(), GetWorld(), GetWorld()->GetFirstPlayerController());
				EventBases.Emplace(Id, Object);
			}
		}
	}

	if (Ar.IsLoading() && NumExpiredEntries > 0)
	{
		for (int32 I = 0; I < NumExpiredEntries; I ++)
		{
			FString Id, PathClass;
			Ar << Id;
			Ar << PathClass;

			TSharedPtr<INEvent> Event = Timeline->GetExpiredEvent(Id);

			if (ensureMsgf(
				Event.IsValid(), TEXT("Event with Uid (\"%s\") can't be retrieved during serialization."), *Id
			))
			{
				UClass* Class = ConstructorHelpersInternal::FindOrLoadClass(PathClass, UNEventBase::StaticClass());
				UNEventBase* Object = NewObject<UNEventBase>(this, Class);
				Object->Serialize(Ar);
				Object->Init(Event, GetCurrentTime(), GetWorld(), GetWorld()->GetFirstPlayerController());
				ExpiredEventBases.Emplace(Id, Object);
			}
		}
	}
}

void UNTimelineManagerDecorator::BeginDestroy()
{
	OnEventChanged().RemoveAll(this);
	Clear();
	Super::BeginDestroy();
}
