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
#include "Factories/Factory.h"

#include "EventFactory.generated.h"

/**
 * Allows to create a blueprint asset in the editor with default event nodes.
 */
UCLASS(hidecategories=Object)
class UNEventFactory : public UFactory
{
	GENERATED_BODY()
public:
	UNEventFactory();

	// ~ Begin UFactory overrides
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
	virtual uint32 GetMenuCategories() const override;
	// ~ End UFactory overrides

	/** The parent class of the created blueprint */
	UPROPERTY(EditAnywhere, Category="EventBaseBlueprintFactory")
	TSubclassOf<class UNEventBase> ParentClass;
};
