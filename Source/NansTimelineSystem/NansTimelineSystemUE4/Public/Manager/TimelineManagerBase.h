#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/Public/TimelineManagerAbstract.h"

#include "TimelineManagerBase.generated.h"

/**
 * TODO Add Serialisation (FArchive) + Save user stats
 */
UCLASS(Abstract)
class NANSTIMELINESYSTEMUE4_API UNTimelineManagerBase : public UObject, public NTimelineManagerAbstract
{
	GENERATED_BODY()
public:
	float Counter = 0;

	template <typename T>
	static T* CreateObject(UObject* Outer, EObjectFlags Flags = EObjectFlags::RF_NoFlags);
	virtual void Init(){};
	virtual void Clear() override;
	virtual void BeginDestroy() override;
	virtual void onNotifyTimelineTickBefore() override;

protected:
	UNTimelineManagerBase();

private:
};
