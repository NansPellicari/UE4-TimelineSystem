#pragma once

#include "CoreMinimal.h"
#include "TimelineManagerBase.h"

#include "GameLifeTimelineManager.generated.h"

UCLASS()
class NANSTIMELINESYSTEMUE4_API UNGameLifeTimelineManager : public UNTimelineManagerBase
{
	GENERATED_BODY()
public:
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;

	virtual void Init();

	virtual void Clear() override;

protected:
	UNGameLifeTimelineManager();

private:
};
