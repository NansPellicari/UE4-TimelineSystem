// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "Timeline.h"

class INEvent;

/** Enum for the NTimelineManager::State */
enum class ENTimelineTimerState : uint8
{
	Played,
	Paused,
	Stopped
};

/**
 * This class is the client for the NTimelineInterface object.
 * Its goal is to decoupled client interface with timeline management.
 *
 * - FNTimeline manages time computation, notify events accordingly and save all event states
 * - NTimelineManager manages client controls.
 *
 * @see NTimelineInterface
 * @see NTimeline
 */
class NANSTIMELINESYSTEMCORE_API FNTimelineManager
{
public:
	/** Calls the Init() method. */
	FNTimelineManager();

	/** Calls Clear() and release Timeline TSharedPtr */
	virtual ~FNTimelineManager();

	/**
	 * Instantiate the embedded NTimeline
	 *
	 * @param InTickInterval - Interval time between tick in sec
	 * @param InLabel - Name of the Timeline.
	 */
	virtual void Init(const float& InTickInterval = 1.f, const FName& InLabel = NAME_None);

	/** This pause the timeline ticking */
	virtual void Pause();

	/** This (re)start the timeline ticking */
	virtual void Play();

	/** This pause the timeline ticking and reset the NTimeline::CurrentTime to 0 */
	virtual void Stop();

	/** This checks the actual play state (ENTimelineTimerState) and tick the NTimelineInterface accordingly. */
	virtual void TimerTick(const float& InDeltaTime);

	/** Get the actual state. */
	ENTimelineTimerState GetState() const;

	/** Get the coupled NTimelineInterface */
	TSharedPtr<FNTimeline> GetTimeline() const;

	/**
	* Creates a new Event and use this timeline as the outer for this new object.
	*
	* @param Name - The label of the event, can be useful for user stats & feedback
	* @param Duration - The time this event is active, 0 to almost INFINI (0 means undetermined time)
	* @param Delay - The time before this event start being active, 0 to almost INFINI (0 means "right now")
	*/
	virtual TSharedPtr<INEvent> CreateNewEvent(const FName& Name, const float& Duration = 0.f,
		const float& Delay = 0.f) const;

	/** @returns a FNTimelineEventDelegate ref which is broadcast when an event changes. */
	FNTimelineEventDelegate& OnEventChanged() const;

	/**
	 * Gives the opportunity to clean data.
	 * This calls Timeline::Clear()
	 */
	virtual void Clear();

	/** Saves/loads State in archive + calls Timeline::Archive() */
	virtual void Archive(FArchive& Ar);

protected:
	/** The actual state */
	ENTimelineTimerState State = ENTimelineTimerState::Stopped;

	/**
	 * This should be used to make some checks right before ticking.
	 * So here you can manipulate State property to (not)allow ticking.
	 */
	virtual void OnValidateTimelineTick(const float& InDeltaTime) {}

	/** This method is call immediately before ticking */
	virtual void OnNotifyTimelineTickBefore(const float& InDeltaTime) {}

	/** This method is call immediately after ticking */
	virtual void OnNotifyTimelineTickAfter(const float& InDeltaTime) {}

	/** The coupled timeline */
	TSharedRef<FNTimeline> Timeline;
};
