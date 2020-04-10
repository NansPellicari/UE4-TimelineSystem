#include "TimelineTimerManagerAbstract.h"

#include "Timeline.h"

NTimelineTimerManagerAbstract::NTimelineTimerManagerAbstract()
{
    CreateTimeline();
}

NTimelineTimerManagerAbstract::~NTimelineTimerManagerAbstract()
{
    Clear();
    Timeline.Reset();
}

void NTimelineTimerManagerAbstract::TimerTick()
{
    // No reason for a timer to tick without a timeline created
    check(Timeline.IsValid());

    if (State == ENTimelineTimerState::Played)
    {
        Timeline->NotifyTick();
    }
}

TSharedPtr<NTimeline> NTimelineTimerManagerAbstract::GetTimeline()
{
    return Timeline;
}

void NTimelineTimerManagerAbstract::SetTickInterval(const float _TickInterval)
{
    TickInterval = _TickInterval;
}

void NTimelineTimerManagerAbstract::CreateTimeline()
{
    new NTimeline(this);
}

void NTimelineTimerManagerAbstract::Play()
{
    // No reason for a timer to play without a timeline created
    check(Timeline.IsValid());
    State = ENTimelineTimerState::Played;
}
void NTimelineTimerManagerAbstract::Pause()
{
    // No reason for a timer to pause without a timeline created
    check(Timeline.IsValid());
    State = ENTimelineTimerState::Paused;
}
void NTimelineTimerManagerAbstract::Stop()
{
    // No reason for a timer to stop without a timeline created
    check(Timeline.IsValid());
    Timeline->Reset();
    Clear();
    State = ENTimelineTimerState::Stopped;
}

void NTimelineTimerManagerAbstract::SetTimeline(NTimeline* _Timeline)
{
    Timeline = MakeShareable<NTimeline>(_Timeline);
}

ENTimelineTimerState NTimelineTimerManagerAbstract::GetState()
{
    return State;
}
