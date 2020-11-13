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
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"

bool NUnrealEventProxy::IsExpired() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->IsExpired();
}

const float NUnrealEventProxy::GetLocalTime() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->GetLocalTime();
}

const float NUnrealEventProxy::GetStartedAt() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->GetStartedAt();
}

float NUnrealEventProxy::GetDuration() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->GetDuration();
}

void NUnrealEventProxy::Start(float StartTime)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->Start(StartTime);
}

void NUnrealEventProxy::Stop()
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->Stop();
}

void NUnrealEventProxy::NotifyAddTime(float NewTime)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->NotifyAddTime(NewTime);
}

float NUnrealEventProxy::GetDelay() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->GetDelay();
}

const FName NUnrealEventProxy::GetEventLabel() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->GetEventLabel();
}

const FString NUnrealEventProxy::GetUID() const
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->GetUID();
}

void NUnrealEventProxy::SetUID(FString _UId)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->SetUID(_UId);
}

void NUnrealEventProxy::SetLocalTime(float _LocalTime)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->SetLocalTime(_LocalTime);
}

void NUnrealEventProxy::SetDuration(float _Duration)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->SetDuration(_Duration);
}

void NUnrealEventProxy::SetDelay(float _Delay)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->SetDelay(_Delay);
}

void NUnrealEventProxy::SetEventLabel(FName _EventLabel)
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->SetEventLabel(_EventLabel);
}

void NUnrealEventProxy::Clear()
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->Clear();
}

FNEventDelegate& NUnrealEventProxy::OnStart()
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	return Event->OnStart();
}

void NUnrealEventProxy::PreDelete()
{
	checkf(IsValid(Event), TEXT("Necessary object is missing!"));
	Event->ConditionalBeginDestroy();
}

void NUnrealEventProxy::ArchiveWithTimeline(FArchive& Ar, UNTimelineDecorator* Timeline)
{
	if (Ar.IsLoading())
	{
		Ar << EventClassName;
		Ar << Label;
		UClass* Class = FindObject<UClass>(ANY_PACKAGE, *EventClassName);
		checkf(Class != nullptr, TEXT("The class \"%s\" was not found"), *EventClassName);
		Event = Timeline->CreateNewEvent(Class, Label);
	}
}

void NUnrealEventProxy::Archive(FArchive& Ar)
{
	if (Ar.IsSaving() && Event != nullptr && Event->GetClass() != nullptr)
	{
		EventClassName = Event->GetClass()->GetPathName();
		Label = Event->GetEventLabel();
		// Only in save cause they have been already retrieved by ArchiveWithTimeline() when Loading
		Ar << EventClassName;
		Ar << Label;
	}

	if (Event != nullptr)
	{
		Event->Serialize(Ar);
	}
}
