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

#include "FakeObject.generated.h"

// About object nomenclature @see https://nirajrules.wordpress.com/2011/08/27/dummy-vs-stub-vs-spy-vs-fake-vs-mock/
UCLASS()
class NANSUE4TESTSHELPERS_API UFakeObject : public UObject
{
	GENERATED_BODY()
public:
	void SetMyWorld(UWorld* World)
	{
		MyWorld = World;
	}

	virtual class UWorld* GetWorld() const override
	{
		return MyWorld;
	}

private:
	UPROPERTY()
	UWorld* MyWorld;
};
