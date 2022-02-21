// Copyright Nans Pellicari, 2021

#include "Pin/TimelinePinFactory.h"

#include "Attribute/ConfiguredTimeline.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"
#include "Pin/ConfiguredTimelinePin.h"
#include "SlateBasics.h"

TSharedPtr<SGraphPin> FTimelinePinFactory::CreatePin(class UEdGraphPin* InPin) const
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
	/*
	 * Check if pin is struct, and then check if that pin is of struct type we want to customize
	 */
	if (InPin->PinType.PinCategory == K2Schema->PC_Struct &&
		InPin->PinType.PinSubCategoryObject == FConfiguredTimeline::StaticStruct())
	{
		// and return our customized pin widget.
		return SNew(SConfiguredTimelinePin, InPin);
	}

	return nullptr;
}
