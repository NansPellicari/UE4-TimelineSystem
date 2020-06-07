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
#include "Event/EventDecorator.h"
#include "Event/EventRecord.h"
#include "NansTimelineSystemCore/Public/EventInterface.h"

#include "TimelineDecorator.generated.h"

class UNTimelineManagerDecorator;

/**
 * The decorator for NTimelineInterface object.
 *
 * It manages:
 * - serialization
 * - attachment of UNEventDecorator object to the embeded NTimeline
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
	 * @see UNTimelineDecorator::Attached(UNEventDecorator* Event)
	 */
	virtual bool Attached(TSharedPtr<NEventInterface> Event) override
	{
		return Timeline->Attached(Event);
	}

	/**
	 * This object should works only with Decorators.
	 * This method is reserved for core objects.
	 * @see UNTimelineDecorator::Attached(UNEventDecorator* Event)
	 */
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) override
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
	virtual void AddEvent(UNEventDecorator* Event);

	/** This retrieve the EventStore */
	const TArray<FNEventRecord> GetAdaptedEvents() const;

	/** Retrieve an event record by its Id */
	FNEventRecord* GetEventRecord(FString UId);

	/**
	 * A delegate attached to NTimeline::EventExpired.
	 * It controls the EventStore data refreshing.
	 *
	 * @param Event - The native Event which will be killed
	 * @param ExpiredTime - The time when this event expires
	 * @param Index - The index of the NTimeline::Events array
	 */
	void OnEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index);

	/**
	 * Creates a new Event and use this timeline as the outer for this new object.
	 *
	 * @param Class - The derived class of your choice
	 * @param Name - The label of the event, can be usefull for user stats & feedback
	 * @param Duration - The time this event is active, 0 to almost INFINI (0 means undeterminated time)
	 * @param Delay - The time before this event start being active, 0 to almost INFINI (0 means "right now")
	 */
	UNEventDecorator* CreateNewEvent(TSubclassOf<UNEventDecorator> Class, FName Name, float Duration = 0.f, float Delay = 0.f);

	/**
	 * It used to save all events state in the EventStore,
	 * and reload them correclty.
	 *
	 * @param Ar - Archive for save and load
	 */
	virtual void Serialize(FArchive& Ar);

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

	/** It is used to convert data for core NTimelineInterface object */
	static NTimeline::FEventTuple ConvertRecordToTuple(FNEventRecord const Record);

private:
	/**
	 * It is a pass-through for NTimelineInterface NTimeline::FEventTuple
	 * and allows to save UNEventDecorator's specializations data.
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
