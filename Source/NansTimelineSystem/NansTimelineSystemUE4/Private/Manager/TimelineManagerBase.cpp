#include "Manager/TimelineManagerBase.h"

#include "Manager/GameLifeTimelineManager.h"
#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "TimerManager.h"

UNTimelineManagerBase::UNTimelineManagerBase()
{
	check(GetOuter());
}

template <typename T>
T* UNTimelineManagerBase::CreateObject(UObject* Outer, EObjectFlags Flags)
{
	T* Obj = NewObject<T>(Outer, NAME_None, Flags);
	Obj->Init();
	return Obj;
}

void UNTimelineManagerBase::onNotifyTimelineTickBefore()
{
	Counter++;
}

void UNTimelineManagerBase::Clear()
{
	NTimelineManagerAbstract::Clear();
	Counter = 0;
}

void UNTimelineManagerBase::BeginDestroy()
{
	Super::BeginDestroy();
}