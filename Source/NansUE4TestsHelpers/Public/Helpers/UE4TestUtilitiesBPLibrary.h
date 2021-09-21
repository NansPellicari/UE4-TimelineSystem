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
