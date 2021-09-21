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

#include "Customization/ConfiguredTimelineCustomization.h"

#include "SlateBasics.h"
#include "SNameComboBox.h"
#include "Attribute/ConfiguredTimeline.h"
#include "Config/TimelineConfig.h"
#include "PropertyEditor/Public/DetailWidgetRow.h"
#include "PropertyEditor/Public/PropertyHandle.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

#define LOCTEXT_NAMESPACE "FactorsFactoryEd"

TSharedRef<IPropertyTypeCustomization> FNConfiguredTimelineCustomization::MakeInstance()
{
	return MakeShareable(new FNConfiguredTimelineCustomization());
}

void FNConfiguredTimelineCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	NameProperty = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FConfiguredTimeline, Name));

	check(NameProperty.IsValid());

	FString Val;
	NameProperty->GetValueAsDisplayString(Val);
	FName NameSelected = FName(*Val);

	TArray<FConfiguredTimelineConf> Settings;
	UNTimelineConfig::GetConfigs(Settings);
	int32 Index = 0;
	NamesList.Empty();
	TSharedPtr<FName> InitialSelectedName;

	for (const auto& Setting : Settings)
	{
		NamesList.Add(MakeShareable(new FName(Setting.Name)));
		if (NameSelected == Setting.Name)
		{
			InitialSelectedName = NamesList[Index];
		}
		Index++;
	}

	Settings.Empty();

	OnAttributeSelected(MakeShareable(new FName(*Val)), ESelectInfo::Direct);

	HeaderRow.NameContent()[StructPropertyHandle->CreatePropertyNameWidget()]
		.ValueContent()[SAssignNew(NameComboBox, SNameComboBox)	   // note you can display any widget here
							.ContentPadding(FMargin(6.0f, 2.0f))
							.OptionsSource(&NamesList)
							.InitiallySelectedItem(InitialSelectedName)
							.OnSelectionChanged(this, &FNConfiguredTimelineCustomization::OnAttributeSelected)];
}

void FNConfiguredTimelineCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class IDetailChildrenBuilder& StructBuilder,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
}
void FNConfiguredTimelineCustomization::OnAttributeSelected(TSharedPtr<FName> Selection, ESelectInfo::Type SelectInfo)
{
	if (NameProperty.IsValid())
	{
		FPropertyAccess::Result Result = NameProperty->SetValueFromFormattedString(Selection->ToString());
	}
}

#undef LOCTEXT_NAMESPACE
