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
#include "Event/TimelineEventDecorator.h"
#include "NansTimelineSystemCore/Public/TimelineEventInterface.h"

#include "TimelineDecorator.generated.h"

class UNTimelineManagerDecorator;

/**
 * This struct is both a pass-through for NTimeline::FEventTuple
 * and a record object used for savegame.
 */
USTRUCT(BlueprintType)
struct NANSTIMELINESYSTEMUE4_API FNEventRecord
{
	GENERATED_USTRUCT_BODY()

	FNEventRecord() {}
	FNEventRecord(
		UNTimelineEventDecorator* _Event, float _AttachedTime, float _Delay, float _Duration, FName _Label, float _ExpiredTime)
		: Event(_Event), AttachedTime(_AttachedTime), Delay(_Delay), Duration(_Duration), Label(_Label), ExpiredTime(_ExpiredTime)
	{
	}

	/** The UNTimelineEventDecorator object */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	UNTimelineEventDecorator* Event = nullptr;
	/** The time it as been attached to the timeline in secs (differ to UNTimelineEventDecorator::StartedAt) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float AttachedTime = -1.f;
	/** The delay before starting in secs */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Delay = -1.f;
	/** The duration this event lives in secs (0 means inderterminate) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Duration = -1.f;
	/** The name of the event */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	FName Label = NAME_None;
	/** Expiration time of this event in secs (0 means can't expired)) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float ExpiredTime = -1.f;
	/** This is used only for serialization, it allow to re-instance the object on load */
	UPROPERTY(SkipSerialization)
	FString EventClassName = FString("");

	/** It manages Event object saving and loading */
	void Serialize(FArchive& Ar, UNTimelineDecorator* Timeline);

	/** Just save basic data, see FNEventRecord::Serialize() to see how Event object is managed */
	friend FArchive& operator<<(FArchive& Ar, FNEventRecord& Record)
	{
		if (Ar.IsSaving())
		{
			Record.EventClassName = Record.Event != nullptr ? Record.Event->GetClass()->GetPathName() : FString("");
		}

		Ar << Record.EventClassName;
		Ar << Record.AttachedTime;
		Ar << Record.Delay;
		Ar << Record.Duration;
		Ar << Record.Label;
		Ar << Record.ExpiredTime;

		return Ar;
	};
};

/**
 * The decorator for NTimelineInterface object.
 *
 * It manages:
 * - serialization
 * - attachment of UNTimelineEventDecorator object to the embeded NTimeline
 */
UCLASS()
class NANSTIMELINESYSTEMUE4_API UNTimelineDecorator : public UObject, public NTimelineInterface
{
	GENERATED_BODY()
public:
	/** Just a default ctor for UObject paradigme */
	UNTimelineDecorator(){};

	/**
	 * this method is used to instanciate the embeded NTimeline
	 * @param TimelineManager - The Decorator which provide the NTimelineManager object.
	 */
	virtual void Init(UNTimelineManagerDecorator* TimelineManager, FName _Label = NAME_None);

	// BEGIN NTimelineInterface overrides
	virtual void Clear() override;
	virtual void SetTickInterval(float _TickInterval) override;
	virtual void SetCurrentTime(float _CurrentTime) override;
	virtual float GetCurrentTime() const override;
	virtual void SetLabel(FName _Label) override;
	virtual FName GetLabel() const;
	virtual void NotifyTick() override;

	/**
	 * This object should works only with Decorators.
	 * This method is reserved for core objects.
	 * @see UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)
	 */
	virtual bool Attached(TSharedPtr<NTimelineEventInterface> Event) override
	{
		return Timeline->Attached(Event);
	}

	/**
	 * This object should works only with Decorators.
	 * This method is reserved for core objects.
	 * @see UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)
	 */
	virtual void Attached(TArray<TSharedPtr<NTimelineEventInterface>> EventsCollection) override
	{
		Timeline->Attached(EventsCollection);
	}
	// END NTimelineInterface overrides

	// BEGIN UObject overrides
	virtual void BeginDestroy() override;
	// END UObject overrides

	TSharedPtr<NTimelineInterface> GetTimeline() const;

	/**
	 * This method is made to work with decorators object.
	 * It will save data in the EventStore array for serialization and save game.
	 * @param Event - The decorator event
	 */
	virtual void AddEvent(UNTimelineEventDecorator* Event);

	/** This retrieve the EventStore */
	const TArray<FNEventRecord> GetAdaptedEvents() const;

	/** It is used to convert data for core NTimelineInterface object */
	static NTimeline::FEventTuple ConvertRecordToTuple(FNEventRecord const Record);

	/**
	 * A delegate attached to NTimeline::EventExpired.
	 * It controls the EventStore data refreshing.
	 *
	 * @param Event - The native Event which will be killed
	 * @param ExpiredTime - The time when this event expires
	 * @param Index - The index of the NTimeline::Events array
	 */
	void OnEventExpired(TSharedPtr<NTimelineEventInterface> Event, const float& ExpiredTime, const int32& Index);

	/**
	 * It used to save all events state in the EventStore,
	 * and reload them correclty.
	 *
	 * @param Ar - Archive for save and load
	 */
	virtual void Serialize(FArchive& Ar);

	/**
	 * Creates a new Event and use this timeline as the outer for this new object.
	 *
	 * @param Class - The derived class of your choice
	 * @param Name - The label of the event, can be usefull for user stats & feedback
	 * @param Duration - The time this event is active, 0 to almost INFINI (0 means undeterminated time)
	 * @param Delay - The time before this event start being active, 0 to almost INFINI (0 means "right now")
	 */
	UNTimelineEventDecorator* CreateNewEvent(
		TSubclassOf<UNTimelineEventDecorator> Class, FName Name, float Duration = 0.f, float Delay = 0.f);

protected:
	/** The embeded object */
	TSharedPtr<NTimeline> Timeline;

	/**
	 * This goal is to synchronize a NTimeline::FEventTuple with is associated FNEventRecord.
	 * It checks coherence with Tuple Event and Record Event before doing it.
	 *
	 * @param Index - The index of the NTimeline::Events array
	 * @param Record - The record you want to synchronize.
	 */
	virtual void RefreshRecordData(const int32& Index);

private:
	/**
	 * It is a pass-through for NTimelineInterface NTimeline::FEventTuple
	 * and allows to save UNTimelineEventDecorator's specializations data.
	 */
	UPROPERTY(SaveGame)
	TArray<FNEventRecord> EventStore;

	UPROPERTY(SaveGame)
	FName Label;

	UPROPERTY(SaveGame)
	float CurrentTime;

	UPROPERTY(SaveGame)
	float TickInterval;
};
