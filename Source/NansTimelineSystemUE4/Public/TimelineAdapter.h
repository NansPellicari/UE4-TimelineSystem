#pragma once

#include "CoreMinimal.h"
#include "Event/TimelineEventAdapter.h"
#include "NansTimelineSystemCore/Public/Timeline.h"

#include "TimelineAdapter.generated.h"

class UNTimelineManagerBaseAdapter;

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

	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	UNTimelineEventAdapter* Event;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float AttachedTime;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Delay;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float Duration;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	FName Label;
	UPROPERTY(SkipSerialization, BlueprintReadOnly, EditInstanceOnly)
	float ExpiredTime;
	UPROPERTY(SkipSerialization)
	UClass* EventClass = nullptr;

	void Serialize(FArchive& Ar, UNTimelineAdapter* Timeline);

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
 * -
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
	const TArray<FNEventRecord> GetAdaptedEvents() const;
	static NTimeline::FEventTuple ConvertRecordToTuple(FNEventRecord const Record);
	virtual void Serialize(FArchive& Ar);
	UNTimelineEventAdapter* CreateNewEvent(
		TSubclassOf<UNTimelineEventAdapter> Class, FName Name, float Duration = 0.f, float Delay = 0.f);

protected:
	TSharedPtr<NTimeline> Timeline;

private:
	UPROPERTY(SaveGame)
	TArray<FNEventRecord> EventStore;
};
