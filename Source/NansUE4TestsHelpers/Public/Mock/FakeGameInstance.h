// Copyright Nans Pellicari, 2021

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
