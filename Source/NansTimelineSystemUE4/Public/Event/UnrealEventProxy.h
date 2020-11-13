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

#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/Public/EventInterface.h"

class UNEventDecorator;

/**
 * This class is just a pass-through to allows an UNEventDecorator (a derived UObject)
 * to be passed on the core system using TSharedPtr.
 */
class NANSTIMELINESYSTEMUE4_API NUnrealEventProxy : public NEventInterface
{
public:
	UNEventDecorator* Event;
	// TODO make this protected and UNTimelineDecorator as friend?
	/** Should be only used by serializer */
	NUnrealEventProxy() {}
	NUnrealEventProxy(UNEventDecorator* _Event) : Event(_Event) {}
	virtual ~NUnrealEventProxy() {}
	virtual bool IsExpired() const override;
	virtual const float GetLocalTime() const override;
	virtual const float GetStartedAt() const override;
	virtual float GetDuration() const override;
	virtual void Start(float StartTime) override;
	virtual void Stop() override;
	virtual void NotifyAddTime(float NewTime) override;
	virtual float GetDelay() const override;
	virtual const FName GetEventLabel() const override;
	virtual const FString GetUID() const override;
	virtual void SetUID(FString _UId) override;
	virtual void SetLocalTime(float _LocalTime) override;
	virtual void SetDuration(float _Duration) override;
	virtual void SetDelay(float _Delay) override;
	virtual void SetEventLabel(FName _EventLabel) override;
	virtual void Clear() override;
	virtual FNEventDelegate& OnStart() override;
	virtual void PreDelete() override;
	virtual void Archive(FArchive& Ar) override;
	void ArchiveWithTimeline(FArchive& Ar, UNTimelineDecorator* Timeline);

protected:
	FString EventClassName;
	FName Label;
	FName UID;
};
