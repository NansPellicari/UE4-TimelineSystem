// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "UnrealTimelineProxy.h"

bool NUnrealTimelineProxy::Attached(TSharedPtr<NEventInterface> Event)
{
	return Timeline.Attached(Event);
}
void NUnrealTimelineProxy::Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection)
{
	return Timeline.Attached(EventsCollection);
}
void NUnrealTimelineProxy::SetTickInterval(float _TickInterval)
{
	Timeline.SetTickInterval(_TickInterval);
}
void NUnrealTimelineProxy::SetCurrentTime(float _CurrentTime)
{
	Timeline.SetCurrentTime(_CurrentTime);
}
float NUnrealTimelineProxy::GetCurrentTime() const
{
	return Timeline.GetCurrentTime();
}
void NUnrealTimelineProxy::SetLabel(FName _Label)
{
	Timeline.SetLabel(_Label);
}
FName NUnrealTimelineProxy::GetLabel() const
{
	return Timeline.GetLabel();
}
void NUnrealTimelineProxy::Clear()
{
	Timeline.Clear();
}
void NUnrealTimelineProxy::NotifyTick()
{
	Timeline.NotifyTick();
}
FNTimelineEventDelegate& NUnrealTimelineProxy::OnEventExpired()
{
	return Timeline.OnEventExpired();
}
void NUnrealTimelineProxy::PreDelete()
{
	Timeline.ConditionalBeginDestroy();
}
void NUnrealTimelineProxy::Archive(FArchive& Ar)
{
	Timeline.Serialize(Ar);
}
const TArray<FNEventSave> NUnrealTimelineProxy::GetEvents() const
{
	return Timeline.GetEvents();
}
TMap<FString, TSharedPtr<NEventInterface>> NUnrealTimelineProxy::GetEventObjects()
{
	return Timeline.GetEventObjects();
}
TSharedPtr<NEventInterface> NUnrealTimelineProxy::GetEvent(FString _UID)
{
	return Timeline.GetEvent(_UID);
}
