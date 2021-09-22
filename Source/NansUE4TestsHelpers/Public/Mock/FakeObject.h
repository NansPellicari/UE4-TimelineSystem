// Copyright Nans Pellicari, 2021

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
