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
