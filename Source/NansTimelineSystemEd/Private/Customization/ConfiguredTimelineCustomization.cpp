
#include "Customization/ConfiguredTimelineCustomization.h"

#include "Config/TimelineConfig.h"
#include "PropertyEditor/Public/DetailLayoutBuilder.h"
#include "PropertyEditor/Public/DetailWidgetRow.h"
#include "PropertyEditor/Public/PropertyHandle.h"
#include "SGraphPin.h"
#include "SNameComboBox.h"
#include "SlateBasics.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SWidget.h"

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
