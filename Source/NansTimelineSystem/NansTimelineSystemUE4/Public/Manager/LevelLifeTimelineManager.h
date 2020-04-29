#pragma once

#include "CoreMinimal.h"
#include "GameLifeTimelineManager.h"
#include "TimelineManagerBase.h"

#include "LevelLifeTimelineManager.generated.h"

UCLASS()
class NANSTIMELINESYSTEMUE4_API UNLevelLifeTimelineManager : public UNGameLifeTimelineManager
{
	GENERATED_BODY()
public:
	virtual void Init() override;
	void OnLevelRemoved(ULevel* Level, UWorld* World);
	void OnLevelChanged();
	void Clear();

protected:
	UNLevelLifeTimelineManager();
	void SaveDataAndClear();

private:
};
