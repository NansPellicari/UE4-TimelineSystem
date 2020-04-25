#pragma once

#include "CoreMinimal.h"

class NTimeline;

enum class ENTimelineTimerState : uint8
{
	Played,
	Paused,
	Stopped
};

class NANSTIMELINESYSTEMCORE_API NTimelineManagerAbstract
{
	friend class NTimeline;

public:
	NTimelineManagerAbstract();
	virtual ~NTimelineManagerAbstract();
	virtual void Pause();
	virtual void Play();
	virtual void Stop();

	void TimerTick();

	ENTimelineTimerState GetState();
	float GetTickInterval();
	TSharedPtr<NTimeline> GetTimeline();

protected:
	/**
	 * The interval retrieve from the timeline.
	 */
	float TickInterval;

	/**
	 * ENTimelineTimerState
	 */
	ENTimelineTimerState State = ENTimelineTimerState::Stopped;
	virtual void CreateTimeline();

	/**
	 * Only accept friend to use it.
	 * This to force their connection in derived class of NTimeline.
	 */
	void SetTimeline(NTimeline* _Timeline);
	// TODO resolve this: Why because It is used in destructor it can't be pure virtual? It is not considered as Abstract class?
	virtual void Clear() {}
	virtual void onNotifyTimelineTickBefore() {}
	virtual void onNotifyTimelineTickAfter() {}
	TSharedPtr<NTimeline> Timeline;
	void SetTickInterval(const float _TickInterval);
};
