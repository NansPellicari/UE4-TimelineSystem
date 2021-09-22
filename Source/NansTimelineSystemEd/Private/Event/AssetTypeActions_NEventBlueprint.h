// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions/AssetTypeActions_Blueprint.h"

/** Allow to defined UNEventBase asset and open it in blueprint editor. */
class FAssetTypeActions_NEventBlueprint : public FAssetTypeActions_Blueprint
{
public:
	// ~ Begin IAssetTypeActions overrides
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects,
		TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
	// ~ End IAssetTypeActions overrides
protected:
	// ~ Begin FAssetTypeActions_ClassTypeBase overrides
	virtual UFactory* GetFactoryForBlueprintType(UBlueprint* InBlueprint) const override;
	// ~ End FAssetTypeActions_ClassTypeBase overrides
};
