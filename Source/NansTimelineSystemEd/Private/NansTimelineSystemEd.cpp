// Copyright Nans Pellicari, 2021

#include "NansTimelineSystemEd.h"

#include "AssetToolsModule.h"
#include "NansTimelineSystemStyle.h"
#include "NansTimelineSystemToolbar.h"
#include "Customization/ConfiguredTimelineCustomization.h"
#include "Event/AssetTypeActions_NEventBlueprint.h"
#include "Modules/ModuleManager.h"
#include "Pin/TimelinePinFactory.h"
#include "PropertyEditor/Public/PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "NansTimelineSystemEdModule"

void FNansTimelineSystemEdModule::StartupModule()
{
	// create your factory and shared pointer to it.
	TimelinePinFactory = MakeShareable(new FTimelinePinFactory());
	// and now register it.
	FEdGraphUtilities::RegisterVisualPinFactory(TimelinePinFactory);

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	// Custom properties
	PropertyModule.RegisterCustomPropertyTypeLayout(
		"ConfiguredTimeline",
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FNConfiguredTimelineCustomization::MakeInstance)
	);

	FNansTimelineSystemStyle::Initialize();

	// Register the EventBaseBlueprint editor asset type actions.
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	AssetTools.RegisterAssetTypeActions(MakeShared<FAssetTypeActions_NEventBlueprint>());

	FNansTimelineSystemToolbar::Initialize();
}

void FNansTimelineSystemEdModule::ShutdownModule()
{
	FEdGraphUtilities::UnregisterVisualPinFactory(TimelinePinFactory);
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		// unregister properties
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(
			"PropertyEditor"
		);
		PropertyModule.UnregisterCustomPropertyTypeLayout("ConfiguredTimeline");
	}

	FNansTimelineSystemStyle::Shutdown();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNansTimelineSystemEdModule, NansTimelineSystemEd)
