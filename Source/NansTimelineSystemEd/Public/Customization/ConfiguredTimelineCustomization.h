#pragma once

#include "PropertyEditor/Public/IPropertyTypeCustomization.h"

class IPropertyHandle;
class FDetailWidgetRow;
class SNameComboBox;

/**
 *
 */
class FNConfiguredTimelineCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
		class FDetailWidgetRow& HeaderRow,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
		class IDetailChildrenBuilder& StructBuilder,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

protected:
	void OnAttributeSelected(TSharedPtr<FName> Selection, ESelectInfo::Type SelectInfo);

private:
	TSharedPtr<IPropertyHandle> NameProperty;
	TArray<TSharedPtr<FName>> NamesList;
	TSharedPtr<SNameComboBox> NameComboBox;
};
