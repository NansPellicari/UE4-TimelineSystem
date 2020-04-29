#pragma once

#include "CoreMinimal.h"

/**
 * An absctract class to manage events which can be attached to a timeline.
 */
class NANSTIMELINESYSTEMCORE_API NTimelineEventBase
{
public:
	virtual bool IsExpired() const;

	/** Should be great to have a doc */
	virtual const float GetLocalTime() const;
	virtual const float GetStartedAt() const;
	virtual float GetDuration() const;
	virtual void Start(float StartTime);
	virtual void NotifyAddTime(float NewTime);
	virtual float GetDelay() const;
	virtual const FName GetEventLabel() const = 0;

	float LocalTime = 0.f;
	float StartedAt = -1.f;
	float Duration = 0.f;
	float Delay = 0.f;
};
