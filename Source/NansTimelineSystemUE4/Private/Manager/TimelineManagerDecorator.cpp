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

#include "Event/EventView.h"
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
	TickInterval = InTickInterval;
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

struct FParamEventChanged
{
	FParamEventChanged() {};
	float InLocalTime = -1.f;
};

void UNTimelineManagerDecorator::OnEventChangedDelegate(TSharedPtr<FNEvent> Event,
	const ENTimelineEvent& EventName, const float& LocalTime, const int32& Index)
{
	UNEventView* EventView = EventViews.FindRef(Event->GetUID());
	check(IsValid(EventView));
	OnBPEventChanged(EventView, LocalTime);

	FString FuncName = FString::Printf(TEXT("On%s"), *EnumToString(EventName));
	UFunction* Func = EventView->FindFunction(FName(FuncName));

	if (Func != nullptr)
	{
		FParamEventChanged Param;
		Param.InLocalTime = LocalTime;
		UE_DEBUG_LOG(
			LogTimelineSystem, Display, TEXT("FuncName \"%s\" for event \"%s\" will be called at %f secs"), *FuncName,
			*EventView->GetEventLabel().ToString(), LocalTime
		);
		EventView->ProcessEvent(Func, &Param);
	}
	else
	{
		UE_DEBUG_LOG(
			LogTimelineSystem, Warning, TEXT("FuncName \"%s\" for event \"%s\" not exists"), *FuncName,
			*EventView->GetEventLabel().ToString()
		);
	}

	if (EventName == ENTimelineEvent::Expired)
	{
		EventViews.Remove(Event->GetUID());
		EventView->ConditionalBeginDestroy();
	}
}

TArray<UNEventView*> UNTimelineManagerDecorator::GetEventViews() const
{
	TArray<UNEventView*> EventRecords;
	EventViews.GenerateValueArray(EventRecords);
	return EventRecords;
}

UNEventView* UNTimelineManagerDecorator::GetEventView(const FString& InUID) const
{
	return EventViews.FindRef(InUID);
}

float UNTimelineManagerDecorator::GetCurrentTime() const
{
	return GetTimeline()->GetCurrentTime();
}

FName UNTimelineManagerDecorator::GetLabel() const
{
	return GetTimeline()->GetLabel();
}

void UNTimelineManagerDecorator::SetLabel(const FName& Name)
{
	GetTimeline()->SetLabel(Name);
}

void UNTimelineManagerDecorator::CreateAndAddNewEvent(FName InName, float InDuration, float InDelay,
	TSubclassOf<UNEventView> InClass)
{
	UClass* ChildClass;
	if (InClass)
	{
		ChildClass = *InClass;
	}
	else
	{
		ChildClass = UNEventView::StaticClass();
	}

	const TSharedPtr<FNEvent> Object = CreateNewEvent(InName, InDuration, InDelay);
	if (!Object.IsValid()) return;

	UNEventView* EventView = NewObject<UNEventView>(this, ChildClass);
	EventView->Init(Object);
	EventViews.Add(Object->GetUID(), EventView);

	GetTimeline()->Attached(Object);
}

void UNTimelineManagerDecorator::Serialize(FArchive& Ar)
{
	// Thanks to the UE4 serializing system, this will serialize all uproperty with "SaveGame"
	Super::Serialize(Ar);
	Archive(Ar);

	int32 NumEntries = 0;

	if (Ar.IsSaving())
	{
		NumEntries = EventViews.Num();
	}

	Ar << NumEntries;

	if (Ar.IsSaving() && NumEntries > 0)
	{
		for (TTuple<FString, UNEventView*> Pair : EventViews)
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

			TSharedPtr<FNEvent> Event = Timeline->GetEvent(Id);

			if (ensureMsgf(
				Event.IsValid(), TEXT("Event with Uid (\"%s\") can't be retrieved during serialization."), *Id
			))
			{
				UClass* Class = ConstructorHelpersInternal::FindOrLoadClass(PathClass, UNEventView::StaticClass());
				UNEventView* Object = NewObject<UNEventView>(this, Class);
				Object->Serialize(Ar);
				Object->Init(Event);
				EventViews.Emplace(Id, Object);
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
