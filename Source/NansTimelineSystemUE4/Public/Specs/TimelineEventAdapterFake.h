#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Event/TimelineEventAdapter.h"
#include "TimerManager.h"

#include "TimelineEventAdapterFake.generated.h"

/**
 * This class is used for tests only
 */
UCLASS(Blueprintable)
class NANSTIMELINESYSTEMUE4_API UNTimelineEventAdapterFake : public UNTimelineEventAdapter
{
	GENERATED_BODY()
};