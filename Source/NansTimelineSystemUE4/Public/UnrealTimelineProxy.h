#pragma once

#include "CoreMinimal.h"
#include "Event//UnrealEventProxy.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/EventInterface.h"
#include "TimelineDecorator.h"

class NANSTIMELINESYSTEMUE4_API UnrealTimelineProxy : public NTimelineInterface
{
public:
	UNTimelineDecorator& Timeline;

	UnrealTimelineProxy(UNTimelineDecorator& _Timeline) : Timeline(_Timeline) {}

	virtual bool Attached(TSharedPtr<NEventInterface> Event) override
	{
		bool bIsAttached = Timeline.Attached(Event);
		if (bIsAttached)
		{
			UnrealEventProxy* Proxy = dynamic_cast<UnrealEventProxy*>(Event.Get());
			checkf(Proxy != nullptr,
				TEXT("The event %s should be wrapped by a UnrealEventProxy before being saved in a timeline"),
				*Event->GetEventLabel().ToString());

			Timeline.AddEvent(&Proxy->GetUnrealObject());
		}
		return bIsAttached;
	}
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) override
	{
		for (auto Event : EventsCollection)
		{
			Attached(EventsCollection);
		}
	}
	virtual void SetTickInterval(float _TickInterval) override
	{
		Timeline.SetTickInterval(_TickInterval);
	}
	virtual void SetCurrentTime(float _CurrentTime) override
	{
		Timeline.SetCurrentTime(_CurrentTime);
	}
	virtual float GetCurrentTime() const override
	{
		return Timeline.GetCurrentTime();
	}
	virtual void SetLabel(FName _Label) override
	{
		Timeline.SetLabel(_Label);
	}
	virtual FName GetLabel() const override
	{
		return Timeline.GetLabel();
	}
	virtual void Clear() override
	{
		Timeline.Clear();
	}
	virtual void NotifyTick() override
	{
		Timeline.NotifyTick();
	}
};
