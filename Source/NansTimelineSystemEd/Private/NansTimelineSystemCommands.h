// Copyright Nans Pellicari, 2021

#pragma once

#include "Framework/Commands/Commands.h"
#include "EditorStyleSet.h"

class FNansTimelineSystemCommands : public TCommands<FNansTimelineSystemCommands>
{
public:
	FNansTimelineSystemCommands()
		: TCommands<FNansTimelineSystemCommands>(
			FName(TEXT("UE4_TimelineSystem")),
			FText::FromString("Timeline System Commands"),
			NAME_None,
			FEditorStyle::GetStyleSetName()
		) { };
	virtual void RegisterCommands() override;
	TSharedPtr<FUICommandInfo> MyButton;
	TSharedPtr<FUICommandInfo> MyMenuButton;
};
