// Copyright Nans Pellicari, 2021

#pragma once

#include "Modules/ModuleManager.h"

NANSTIMELINESYSTEMUE4_API DECLARE_LOG_CATEGORY_EXTERN(LogTimelineSystem, Log, All);

#define UE_DEBUG_LOG(CategoryName, Verbosity, Format, ...) \
if (bDebug) {\
UE_LOG(CategoryName, Verbosity, Format, ##__VA_ARGS__); \
}

/** Required to create a UE4 module */
class FNansTimelineSystemUE4Module : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	/** IModuleInterface implementation */
	virtual void ShutdownModule() override;

private:
	TSet<FName> RegisteredPropertyTypes;
};
