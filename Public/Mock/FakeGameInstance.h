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

#include "Runtime/Engine/Classes/Engine/GameInstance.h"

#include "FakeGameInstance.generated.h"

// About test object's nomenclature @see https://nirajrules.wordpress.com/2011/08/27/dummy-vs-stub-vs-spy-vs-fake-vs-mock/

UCLASS()
class NANSUE4TESTSHELPERS_API UFakeGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	void SetWorldContext(struct FWorldContext* _WorldContext)
	{
		WorldContext = _WorldContext;
	}
};
