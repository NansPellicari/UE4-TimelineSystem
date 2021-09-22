// Copyright Nans Pellicari, 2021

#include "Event/AssetTypeActions_NEventBlueprint.h"

#include "BlueprintEditor.h"
#include "Event/EventBase.h"
#include "Event/EventFactory.h"

#define LOCTEXT_NAMESPACE "EventFactory"

UFactory* FAssetTypeActions_NEventBlueprint::GetFactoryForBlueprintType(UBlueprint* InBlueprint) const
{
	UNEventFactory* GameplayAbilitiesBlueprintFactory = NewObject<UNEventFactory>();
	GameplayAbilitiesBlueprintFactory->ParentClass = TSubclassOf<UNEventBase>(*InBlueprint->GeneratedClass);
	return GameplayAbilitiesBlueprintFactory;
}

FText FAssetTypeActions_NEventBlueprint::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_NEventBlueprint", "Timeline Event");
}

FColor FAssetTypeActions_NEventBlueprint::GetTypeColor() const
{
	return FColor::Yellow;
}

UClass* FAssetTypeActions_NEventBlueprint::GetSupportedClass() const
{
	return UNEventBaseBlueprint::StaticClass();
}

uint32 FAssetTypeActions_NEventBlueprint::GetCategories()
{
	return EAssetTypeCategories::Gameplay;
}

void FAssetTypeActions_NEventBlueprint::OpenAssetEditor(const TArray<UObject*>& InObjects,
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
								   "FailedToLoadEventBlueprintWithContinue",
								   "Event Blueprint could not be loaded because it derives from an invalid class.  Check to make sure the parent class for this blueprint hasn't been removed! Do you want to continue (it can crash the editor)?"
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
					"FailedToLoadEventBlueprint",
					"Event View Blueprint could not be loaded because it derives from an invalid class.  Check to make sure the parent class for this blueprint hasn't been removed!"
				)
			);
		}
	}
}
#undef LOCTEXT_NAMESPACE
