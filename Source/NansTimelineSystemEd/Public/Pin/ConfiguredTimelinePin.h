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

#pragma once

#include "CoreMinimal.h"
#include "SGraphPin.h"
#include "SlateBasics.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SWidget.h"
#include "Config/TimelineConfig.h"

class SNameComboBox;

// You can also check files in the engine to see a lot of examples here:
// [UE4 directory]\Engine\Source\Editor\GraphEditor\Private\KismetPins\SGraphPinCollisionProfile.h

/**
 * This class allows to create a dedicated pin to get names from UNTimelineConfig.
 *
 * @see UNTimelineConfig
 */
class SConfiguredTimelinePin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SConfiguredTimelinePin) {}
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj);

protected:
	// this override is used to display slate widget used for customization.
	virtual TSharedRef<SWidget> GetDefaultValueWidget() override;

	/**
	 * It is called by the combobox SNameComboBox::OnSelectionChanged() event.
	 * It checks selected data and saved it to the node.
	 */
	void OnAttributeSelected(TSharedPtr<FName> ItemSelected, ESelectInfo::Type SelectInfo);

	/**
	 * It is called by the combobox SNameComboBox::OnComboBoxOpening() event.
	 * It checks if data selected is valid and set a the selected item for the combobox.
	 */
	void OnComboBoxOpening();

	/**
	 * Get the previous selected or default name from Names.
	 */
	TSharedPtr<FName> GetSelectedName() const;

	/**
	 * It is called by OnAttributeSelected() only.
	 * It saves the selected name in the blueprint node.
	 *
	 * * @param Name - A FName reference which saved retrieved or default value.
	 */
	void SetPropertyWithName(const FName& Name);

	/**
	 * It is called by GetSelectedName() only.
	 * Try to retrieve property from the GraphPin Object.
	 * @param Name - A FName reference which saved retrieved value.
	 */
	void GetPropertyAsName(FName& OutName) const;

private:
	/**
	 * List retrieved from the UNTimelineConfig::GetConfigs().
	 * @see GetDefaultValueWidget() to know how.
	 */
	TArray<FConfiguredTimelineConf> AttributesList;

	/** Names extract from the AttributesList */
	TArray<TSharedPtr<FName>> Names;

	/** A reference to the dedicated widget */
	TSharedPtr<SNameComboBox> NameComboBox;
};
