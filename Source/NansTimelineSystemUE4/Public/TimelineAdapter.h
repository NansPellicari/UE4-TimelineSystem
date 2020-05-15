#pragma once

#include "CoreMinimal.h"
#include "Event/TimelineEventAdapter.h"
#include "NansTimelineSystemCore/Public/Timeline.h"

#include "TimelineAdapter.generated.h"

class UNTimelineManagerBaseAdapter;

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
		UNTimelineEventAdapter* _Event, float _AttachedTime, float _Delay, float _Duration, FName _Label, float _ExpiredTime)
		: Event(_Event), AttachedTime(_AttachedTime), Delay(_Delay), Duration(_Duration), Label(_Label), ExpiredTime(_ExpiredTime)
	{
	}

	/** The UNTimelineEventAdapter object */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	UNTimelineEventAdapter* Event;
	/** The time it as been attached to the timeline in secs (differ to UNTimelineEventAdapter::StartedAt) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float AttachedTime;
	/** The delay before starting in secs */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Delay;
	/** The duration this event lives in secs (0 means inderterminate) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Duration;
	/** The name of the event */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	FName Label;
	/** Expiration time of this event in secs (0 means can't expired)) */
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float ExpiredTime;
	/** This is used only for serialization, it allow to re-instance the object on load */
	UPROPERTY(SkipSerialization)
	UClass* EventClass = nullptr;

	/** It manages Event object saving and loading */
	void Serialize(FArchive& Ar, UNTimelineAdapter* Timeline);

	/** Just save basic data, see FNEventRecord::Serialize() to see how Event object is managed */
	friend FArchive& operator<<(FArchive& Ar, FNEventRecord& Record)
	{
		if (Ar.IsSaving() && Record.Event != nullptr)
		{
			Record.EventClass = Record.Event->GetClass();
		}

		Ar << Record.EventClass;
		Ar << Record.AttachedTime;
		Ar << Record.Delay;
		Ar << Record.Duration;
		Ar << Record.Label;
		Ar << Record.ExpiredTime;

		return Ar;
	};
};

/**
 * The adapter for NTimeline object.
 *
 * It manages:
 * - serialization
 * - attachment of UNTimelineEventAdapter object to the embeded NTimeline
 */
UCLASS()
class NANSTIMELINESYSTEMUE4_API UNTimelineAdapter : public UObject, public NTimeline
{
	GENERATED_BODY()
public:
	/** Just a default ctor for UObject paradigme */
	UNTimelineAdapter(){};

	/**
	 * this method is used to instanciate the embeded NTimeline
	 * @param TimelineManager - The Adapter which provide the NTimelineManagerAbstract object.
	 */
	virtual void Init(UNTimelineManagerBaseAdapter* TimelineManager, FName _Label = NAME_None);

	// BEGIN NTimeline overrides
	virtual void Clear() override;
	virtual void SetCurrentTime(float _CurrentTime);
	virtual float GetCurrentTime();
	virtual void SetLabel(FName _Label) override;
	virtual FName GetLabel() const;
	virtual void NotifyTick() override;

	/**
	 * This object should works only with Adapters.
	 * This method is reserved for core objects.
	 * @see UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)
	 */
	virtual void Attached(TSharedPtr<NTimelineEventBase> Event) override
	{
		UE_LOG(LogTemp, Fatal, TEXT("You should use UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event) instead!"));
	}

	/**
	 * This object should works only with Adapters.
	 * This method is reserved for core objects.
	 * @see UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)
	 */
	virtual void Attached(TArray<TSharedPtr<NTimelineEventBase>> EventsCollection) override
	{
		UE_LOG(LogTemp, Fatal, TEXT("You should use UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event) instead!"));
	}
	// END NTimeline overrides

	// BEGIN UObject overrides
	virtual void BeginDestroy() override;
	// END UObject overrides

	TSharedPtr<NTimeline> GetTimeline() const;

	/**
	 * This method is made to work with adapters object.
	 * It will save data in the EventStore array for serialization and save game.
	 * @param Event - The adapter event
	 */
	virtual void Attached(UNTimelineEventAdapter* Event);

	/** This retrieve the EventStore */
	const TArray<FNEventRecord> GetAdaptedEvents() const;

	/** It is used to convert data for core NTimeline object */
	static NTimeline::FEventTuple ConvertRecordToTuple(FNEventRecord const Record);

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
	UNTimelineEventAdapter* CreateNewEvent(
		TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration = 0.f, float Delay = 0.f);

protected:
	/** The embeded object */
	TSharedPtr<NTimeline> Timeline;

private:
	/**
	 * It is a pass-through for NTimeline NTimeline::FEventTuple
	 * and allows to save UNTimelineEventAdapter's specializations data.
	 */
	UPROPERTY(SaveGame)
	TArray<FNEventRecord> EventStore;
};
