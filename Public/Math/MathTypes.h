// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "CoreMinimal.h"

#include "MathTypes.generated.h"

USTRUCT(BlueprintType)
struct FRange
{
	GENERATED_USTRUCT_BODY()

public:
	FRange() {}
	FRange(float _Lh, float _Rh) : Lh(_Lh), Rh(_Rh) {}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")
	float Lh = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")
	float Rh = 100;

	float GetBoundValue(const float& Percent) const
	{
		float MinBound = FMath::Min(Lh, Rh);
		float MaxBound = FMath::Max(Lh, Rh);
		return (MaxBound - MinBound) * Percent + MinBound;
	}
};
