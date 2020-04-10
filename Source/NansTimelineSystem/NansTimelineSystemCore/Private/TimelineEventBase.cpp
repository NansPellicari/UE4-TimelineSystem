#include "TimelineEventBase.h"

bool NTimelineEventBase::IsExpired() const
{
    return GetDuration() > 0 && GetLocalTime() >= GetDuration();
};

const float NTimelineEventBase::GetLocalTime() const
{
    return LocalTime;
}

const float NTimelineEventBase::GetStartedAt() const
{
    return StartedAt;
}

float NTimelineEventBase::GetDuration() const
{
    return Duration;
}

void NTimelineEventBase::Start(float StartTime)
{
    StartedAt = StartTime;
}

void NTimelineEventBase::NotifyAddTime(float NewTime)
{
    LocalTime += NewTime;
}

float NTimelineEventBase::GetDelay() const
{
    return Delay;
}
