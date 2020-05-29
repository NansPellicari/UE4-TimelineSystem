#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/Public/TimelineEventBase.h"

class NANSTIMELINESYSTEMUE4_API UnrealTimelineEventProxy : public NTimelineEventInterface
{
public:
	UNTimelineEventDecorator& Event;
	UnrealTimelineEventProxy(UNTimelineEventDecorator& _Event) : Event(_Event) {}

	virtual ~UnrealTimelineEventProxy()
	{
		Event.ConditionalBeginDestroy();
	}
	virtual bool IsExpired() const
	{
		return Event.IsExpired();
	}

	virtual const float GetLocalTime() const
	{
		return Event.GetLocalTime();
	}

	virtual const float GetStartedAt() const
	{
		return Event.GetStartedAt();
	}

	virtual float GetDuration() const
	{
		return Event.GetDuration();
	}

	virtual void Start(float StartTime)
	{
		Event.Start(StartTime);
	}

	virtual void NotifyAddTime(float NewTime)
	{
		Event.NotifyAddTime(NewTime);
	}

	virtual float GetDelay() const
	{
		return Event.GetDelay();
	}

	virtual const FName GetEventLabel() const
	{
		return Event.GetEventLabel();
	}

	virtual const FString GetUID() const
	{
		return Event.GetUID();
	}

	virtual void SetLocalTime(float _LocalTime)
	{
		Event.SetLocalTime(_LocalTime);
	}

	virtual void SetStartedAt(float _StartedAt)
	{
		Event.SetStartedAt(_StartedAt);
	}

	virtual void SetDuration(float _Duration)
	{
		Event.SetDuration(_Duration);
	}

	virtual void SetDelay(float _Delay)
	{
		Event.SetDelay(_Delay);
	}

	virtual void SetEventLabel(FName _EventLabel)
	{
		Event.SetEventLabel(_EventLabel);
	}

	virtual void Clear()
	{
		Event.Clear();
	}

	UNTimelineEventDecorator& GetUnrealObject()
	{
		return Event;
	}
};