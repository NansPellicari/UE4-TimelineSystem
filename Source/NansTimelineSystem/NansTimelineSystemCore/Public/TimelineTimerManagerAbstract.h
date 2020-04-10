#pragma once

#include "CoreMinimal.h"

class NTimeline;

enum class ENTimelineTimerState : uint8
{
    Played,
    Paused,
    Stopped
};

class NANSTIMELINESYSTEMCORE_API NTimelineTimerManagerAbstract
{
    friend class NTimeline;

public:
    NTimelineTimerManagerAbstract();
    virtual ~NTimelineTimerManagerAbstract();
    virtual void Pause();
    virtual void Play();
    virtual void Stop();

    void TimerTick();

    ENTimelineTimerState GetState();
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
    TSharedPtr<NTimeline> Timeline;
    void SetTickInterval(const float _TickInterval);
};
