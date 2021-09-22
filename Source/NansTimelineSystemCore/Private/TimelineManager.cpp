// Copyright Nans Pellicari, 2021

#include "TimelineManager.h"

#include "Timeline.h"
#include "Math/UnitConversion.h"

FNTimelineManager::FNTimelineManager() : Timeline(MakeShared<FNTimeline>()) {}

FNTimelineManager::~FNTimelineManager() {}

void FNTimelineManager::TimerTick(const float& InDeltaTime)
{
	OnValidateTimelineTick(InDeltaTime);
	if (State == ENTimelineTimerState::Played)
	{
		OnNotifyTimelineTickBefore(InDeltaTime);
		Timeline->NotifyTick(InDeltaTime);
		OnNotifyTimelineTickAfter(InDeltaTime);
	}
}

TSharedPtr<FNTimeline> FNTimelineManager::GetTimeline() const
{
	return Timeline;
}

ENTimelineTimerState FNTimelineManager::GetState() const
{
	return State;
}

void FNTimelineManager::Init(const float& InTickInterval, const FName& InLabel)
{
	Timeline->SetTickInterval(InTickInterval);
	if (InLabel != NAME_None)
	{
		Timeline->SetLabel(InLabel);
	}
}

void FNTimelineManager::Play()
{
	State = ENTimelineTimerState::Played;
}

void FNTimelineManager::Pause()
{
	State = ENTimelineTimerState::Paused;
}

void FNTimelineManager::Stop()
{
	Timeline->Clear();
	State = ENTimelineTimerState::Stopped;
}

TSharedPtr<INEvent> FNTimelineManager::CreateNewEvent(const FName& Name, const float& Duration,
	const float& Delay) const
{
	FName NewName = Name;

	if (NewName == NAME_None)
	{
		static int32 Counter;
		const FString EvtLabel = FString::Format(TEXT("EventBase_{0}"), {++Counter});
		NewName = FName(*EvtLabel);
	}

	TSharedPtr<INEvent> Object = MakeShared<FNEvent>(NewName);
	if (Duration > 0)
	{
		Object->SetDuration(Duration);
	}
	if (Delay > 0)
	{
		Object->SetDelay(Delay);
	}

	return Object;
}

void FNTimelineManager::Clear()
{
	Timeline->Clear();
}

FNTimelineEventDelegate& FNTimelineManager::OnEventChanged() const
{
	return Timeline->EventChanged;
}

void FNTimelineManager::Archive(FArchive& Ar)
{
	Timeline->Archive(Ar);
	Ar << State;
}
