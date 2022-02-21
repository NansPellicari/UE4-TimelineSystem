// Copyright Nans Pellicari, 2021

#include "NansTimelineSystemCommands.h"

void FNansTimelineSystemCommands::RegisterCommands()
{
#define LOCTEXT_NAMESPACE ""
	UI_COMMAND(
		MyButton, "TimelineSystem", "TimelineSystem Toolbar Command", EUserInterfaceActionType::Button, FInputChord()
	);
	UI_COMMAND(
		MyMenuButton, "TimelineSystem", "TimelineSystem Toolbar Command", EUserInterfaceActionType::Button, FInputChord()
	);
#undef LOCTEXT_NAMESPACE
}
