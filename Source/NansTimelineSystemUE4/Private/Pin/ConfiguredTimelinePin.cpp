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

#include "Pin/ConfiguredTimelinePin.h"

#include "Attribute/ConfiguredTimeline.h"
#include "Config/TimelineConfig.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphSchema.h"
#include "SNameComboBox.h"
#include "ScopedTransaction.h"

void SConfiguredTimelinePin::Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InGraphPinObj);
}

TSharedRef<SWidget> SConfiguredTimelinePin::GetDefaultValueWidget()
{
	UNTimelineConfig::GetConfigs(AttributesList);
	for (auto& Attr : AttributesList)
	{
		Names.Add(MakeShareable(new FName(Attr.Name)));
	}

	// retrieve the previous value selected (or the first value as default)
	TSharedPtr<FName> PreviousSelectedName = GetSelectedName();
	TSharedPtr<FName> CurrentlySelectedName;

	// It is possible if no configured timelines have been created.
	if (PreviousSelectedName.IsValid())
	{
		CurrentlySelectedName = PreviousSelectedName;
	}

	return SAssignNew(NameComboBox, SNameComboBox)		 // you can display any widget here
		.ContentPadding(FMargin(6.0f, 2.0f))			 // you can stylize how you want by the way, check Slate library
		.OptionsSource(&Names)							 // this to create all possibilities
		.InitiallySelectedItem(CurrentlySelectedName)	 // the default or previous selected value
		.OnComboBoxOpening(this, &SConfiguredTimelinePin::OnComboBoxOpening)		// this event is defined by the SNameComboBox
		.OnSelectionChanged(this, &SConfiguredTimelinePin::OnAttributeSelected);	// dito
}

void SConfiguredTimelinePin::OnAttributeSelected(TSharedPtr<FName> ItemSelected, ESelectInfo::Type SelectInfo)
{
	if (ItemSelected.IsValid())
	{
		SetPropertyWithName(*ItemSelected);
	}
}

void SConfiguredTimelinePin::OnComboBoxOpening()
{
	TSharedPtr<FName> SelectedName = GetSelectedName();
	if (SelectedName.IsValid())
	{
		check(NameComboBox.IsValid());
		NameComboBox->SetSelectedItem(SelectedName);
	}
}

void SConfiguredTimelinePin::SetPropertyWithName(const FName& Name)
{
	check(GraphPinObj);
	check(GraphPinObj->PinType.PinSubCategoryObject == FConfiguredTimeline::StaticStruct());

	FString ClassName;
	for (auto& Config : AttributesList)
	{
		if (Name == Config.Name)
		{
			ClassName = Config.TimelineClass->GetPathName();
			break;
		}
	}

	// To set the property we need to use a FString
	// using this format: (Name="My Value",TimelineClass="/Script/MyClass")
	// Name & TimelineClass are properties defined in our struct FConfiguredTimeline
	FString PinString = FString::Format(TEXT("(Name=\"{0}\",TimelineClass=\"{1}\")"), {Name.ToString(), ClassName});

	FString CurrentDefaultValue = GraphPinObj->GetDefaultAsString();

	if (CurrentDefaultValue != PinString)
	{
		const FScopedTransaction Transaction(
			NSLOCTEXT("GraphEditor", "ChangeNameFromTimelinegPinValue", "Change Name From Timeline Pin Value"));
		GraphPinObj->Modify();

		if (PinString != GraphPinObj->GetDefaultAsString())
		{
			// Its important to use this function instead of GraphPinObj->DefaultValue
			// directly, cause it notifies the node from the pin is attached to.
			// So the node can listen this change and do things internally.
			GraphPinObj->GetSchema()->TrySetDefaultValue(*GraphPinObj, PinString);
		}
	}
}

TSharedPtr<FName> SConfiguredTimelinePin::GetSelectedName() const
{
	int32 NameCount = Names.Num();
	if (NameCount <= 0)
	{
		return NULL;
	}

	FName Name;
	GetPropertyAsName(Name);

	for (auto& Elem : Names)
	{
		if (Name == *Elem.Get())
		{
			return Elem;
		}
	}
	// no value has been found, return a default value
	return Names[0];
}

void SConfiguredTimelinePin::GetPropertyAsName(FName& OutName) const
{
	check(GraphPinObj);
	check(GraphPinObj->PinType.PinSubCategoryObject == FConfiguredTimeline::StaticStruct());

	// As we saw in the SConfiguredTimelinePin::SetPropertyWithName()
	// The value is saved in the format (Name="My Value",TimelineClass="/Script/myClass") as a FString.
	// So we have to retrieve the real value and convert it to a FName
	FString PinString = GraphPinObj->GetDefaultAsString();

	if (PinString.StartsWith(TEXT("(")) && PinString.EndsWith(TEXT(")")))
	{
		PinString = PinString.LeftChop(1);
		PinString = PinString.RightChop(1);
		FString ClassNameString;
		FString NameString;
		PinString.Split(TEXT(","), &NameString, &ClassNameString);
		FString ResultString = NameString;
		ResultString.TrimStartAndEnd().Split(TEXT("="), NULL, &PinString);
		PinString = PinString.TrimQuotes();
	}

	if (!PinString.IsEmpty())
	{
		OutName = *PinString;
	}
}
