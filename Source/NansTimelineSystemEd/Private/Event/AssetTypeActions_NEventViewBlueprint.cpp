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

#include "Event/AssetTypeActions_NEventViewBlueprint.h"

#include "BlueprintEditor.h"
#include "Event/EventView.h"
#include "Event/EventViewFactory.h"

#define LOCTEXT_NAMESPACE "EventViewFactory"

UFactory* FAssetTypeActions_NEventViewBlueprint::GetFactoryForBlueprintType(UBlueprint* InBlueprint) const
{
	UNEventViewFactory* GameplayAbilitiesBlueprintFactory = NewObject<UNEventViewFactory>();
	GameplayAbilitiesBlueprintFactory->ParentClass = TSubclassOf<UNEventView>(*InBlueprint->GeneratedClass);
	return GameplayAbilitiesBlueprintFactory;
}

FText FAssetTypeActions_NEventViewBlueprint::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_NEventViewBlueprint", "Timeline Event View");
}

FColor FAssetTypeActions_NEventViewBlueprint::GetTypeColor() const
{
	return FColor::Yellow;
}

UClass* FAssetTypeActions_NEventViewBlueprint::GetSupportedClass() const
{
	return UNEventViewBlueprint::StaticClass();
}

uint32 FAssetTypeActions_NEventViewBlueprint::GetCategories()
{
	return EAssetTypeCategories::Gameplay;
}

void FAssetTypeActions_NEventViewBlueprint::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
										? EToolkitMode::WorldCentric
										: EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		UBlueprint* Blueprint = Cast<UBlueprint>(*ObjIt);
		if (Blueprint)
		{
			bool bLetOpen = true;
			if (!Blueprint->ParentClass)
			{
				bLetOpen = EAppReturnType::Yes == FMessageDialog::Open(
							   EAppMsgType::YesNo,
							   LOCTEXT(
								   "FailedToLoadEventViewBlueprintWithContinue",
								   "EventView Blueprint could not be loaded because it derives from an invalid class.  Check to make sure the parent class for this blueprint hasn't been removed! Do you want to continue (it can crash the editor)?"
							   )
						   );
			}

			if (bLetOpen)
			{
				TSharedRef<FBlueprintEditor> NewEditor(new FBlueprintEditor());

				TArray<UBlueprint*> Blueprints;
				Blueprints.Add(Blueprint);

				NewEditor->InitBlueprintEditor(Mode, EditWithinLevelEditor, Blueprints, false);
			}
		}
		else
		{
			FMessageDialog::Open(
				EAppMsgType::Ok, LOCTEXT(
					"FailedToLoadEventViewBlueprint",
					"Event View Blueprint could not be loaded because it derives from an invalid class.  Check to make sure the parent class for this blueprint hasn't been removed!"
				)
			);
		}
	}
}
#undef LOCTEXT_NAMESPACE
