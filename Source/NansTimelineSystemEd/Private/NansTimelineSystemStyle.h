// Copyright Nans Pellicari, 2021

#pragma once

#include "Styling/ISlateStyle.h"
#include "Styling/SlateStyle.h"

class FNansTimelineSystemStyle
{
public:
	static void Initialize();

	static void Shutdown();

	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:
	static TSharedRef<FSlateStyleSet> Create();
	static TSharedPtr<FSlateStyleSet> StyleInstance;
};
