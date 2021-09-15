// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
