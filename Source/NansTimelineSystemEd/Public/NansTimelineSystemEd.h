// Copyright Nans Pellicari, 2021

#pragma once

#include "Modules/ModuleManager.h"

class FTimelinePinFactory;

class FNansTimelineSystemEdModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	TSharedPtr<FTimelinePinFactory> TimelinePinFactory;
	
};
