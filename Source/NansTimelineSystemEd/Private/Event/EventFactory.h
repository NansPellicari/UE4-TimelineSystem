// Copyright Nans Pellicari, 2021

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
