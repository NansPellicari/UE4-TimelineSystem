// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NansTimelineSystemUE4.h"

#include "TimelinePinFactory.h"

#define LOCTEXT_NAMESPACE "FNansTimelineSystemUE4Module"

void FNansTimelineSystemUE4Module::StartupModule()
{
	// create your factory and shared pointer to it.
	TSharedPtr<FTimelinePinFactory> Factory = MakeShareable(new FTimelinePinFactory());
	// and now register it.
	FEdGraphUtilities::RegisterVisualPinFactory(Factory);
}

void FNansTimelineSystemUE4Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNansTimelineSystemUE4Module, NansTimelineSystemUE4)