// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#include "EdGraphUtilities.h"
#include "SlateBasics.h"

/**
 * It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.
 *
 * @see FNansTimelineSystemUE4Module::StartupModule()
 */
class FTimelinePinFactory : public FGraphPanelPinFactory
{
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* InPin) const override;
};
