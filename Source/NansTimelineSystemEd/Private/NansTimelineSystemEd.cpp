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

#include "NansTimelineSystemEd.h"

#include "AssetToolsModule.h"
#include "NansTimelineSystemStyle.h"
#include "Customization/ConfiguredTimelineCustomization.h"
#include "Event/AssetTypeActions_NEventViewBlueprint.h"
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

	// Register the EventViewBlueprint editor asset type actions.
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	AssetTools.RegisterAssetTypeActions(MakeShared<FAssetTypeActions_NEventViewBlueprint>());
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
