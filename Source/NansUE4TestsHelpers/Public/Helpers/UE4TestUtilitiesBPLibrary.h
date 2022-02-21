// Copyright Nans Pellicari, 2021

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UE4TestUtilitiesBPLibrary.generated.h"

class UUserWidget;
class UWidget;

/**
 * Comment
 */
UENUM(BlueprintType)
enum class ETestUtilitiesMouseClick : uint8
{
	LEFT UMETA(DisplayName = "Mouse button left"),
	RIGHT UMETA(DisplayName = "Mouse button right")
};


UCLASS()
class UNUE4TestUtilitiesBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Click", Keywords =
		"TestUtilities click testing"), Category = "Utilities|Test")
	static void TestUtilitiesClick(UWidget* Widget, bool& bSuccess,
		ETestUtilitiesMouseClick ClickBtn = ETestUtilitiesMouseClick::LEFT);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Touch", Keywords =
		"TestUtilities touch testing"), Category = "Utilities|Test")
	static void TestUtilitiesTouch(UWidget* Widget, bool& bSuccess);
};
