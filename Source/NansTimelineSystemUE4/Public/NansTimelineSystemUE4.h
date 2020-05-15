// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** Required to create a UE4 module */
class FNansTimelineSystemUE4Module : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	/** IModuleInterface implementation */
	virtual void ShutdownModule() override;
};
