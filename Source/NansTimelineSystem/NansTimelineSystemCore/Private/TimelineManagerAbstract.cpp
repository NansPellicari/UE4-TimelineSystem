#include "TimelineManagerAbstract.h"

#include "Timeline.h"

NTimelineManagerAbstract::NTimelineManagerAbstract()
{
	CreateTimeline();
}

NTimelineManagerAbstract::~NTimelineManagerAbstract()
{
	Clear();
	Timeline.Reset();
}

void NTimelineManagerAbstract::TimerTick()
{
	// No reason for a timer to tick without a timeline created
	check(Timeline.IsValid());

	if (State == ENTimelineTimerState::Played)
	{
		onNotifyTimelineTickBefore();
		Timeline->NotifyTick();
		onNotifyTimelineTickAfter();
	}
}

TSharedPtr<NTimeline> NTimelineManagerAbstract::GetTimeline()
{
	return Timeline;
}

float NTimelineManagerAbstract::GetTickInterval()
{
	return TickInterval;
}

void NTimelineManagerAbstract::SetTickInterval(const float _TickInterval)
{
	TickInterval = _TickInterval;
}

void NTimelineManagerAbstract::CreateTimeline()
{
	new NTimeline(this);
}

void NTimelineManagerAbstract::Play()
{
	// No reason for a timer to play without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Played;
}
void NTimelineManagerAbstract::Pause()
{
	// No reason for a timer to pause without a timeline created
	check(Timeline.IsValid());
	State = ENTimelineTimerState::Paused;
}
void NTimelineManagerAbstract::Stop()
{
	// No reason for a timer to stop without a timeline created
	check(Timeline.IsValid());
	Timeline->Reset();
	Clear();
	State = ENTimelineTimerState::Stopped;
}

void NTimelineManagerAbstract::SetTimeline(NTimeline* _Timeline)
{
	Timeline = MakeShareable<NTimeline>(_Timeline);
}

ENTimelineTimerState NTimelineManagerAbstract::GetState()
{
	return State;
}
