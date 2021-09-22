// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FNansCoreHelpersModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
