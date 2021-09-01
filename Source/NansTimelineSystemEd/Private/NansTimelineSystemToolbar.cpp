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

#include "NansTimelineSystemToolbar.h"

#include "LevelEditor.h"
#include "NansTimelineSystemCommands.h"
#include "NansTimelineSystemEd.h"
#include "NansTimelineSystemStyle.h"
#include "Editor/MainFrame/Public/Interfaces/IMainFrameModule.h"
#include "UI/SWindowTimeline.h"

TSharedPtr<FNansTimelineSystemToolbar> FNansTimelineSystemToolbar::Instance = nullptr;

void FNansTimelineSystemToolbar::Initialize()
{
	if (!Instance.IsValid())
	{
		Instance = MakeShared<FNansTimelineSystemToolbar>();
		Instance->Register();
	}
}

void FNansTimelineSystemToolbar::Shutdown()
{
	ensure(Instance.IsUnique());
	Instance->Unregister();
	Instance.Reset();
}

void FNansTimelineSystemToolbar::Register()
{
	FNansTimelineSystemCommands::Register();
	TSharedPtr<FUICommandList> CommandList = MakeShareable(new FUICommandList());
	CommandList->MapAction(
		FNansTimelineSystemCommands::Get().MyButton,
		FExecuteAction::CreateRaw(this, &FNansTimelineSystemToolbar::MyButton_Clicked), FCanExecuteAction()
	);

	ToolbarExtender = MakeShareable(new FExtender());
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	Extension = ToolbarExtender->AddToolBarExtension(
		"Compile", EExtensionHook::Before, CommandList, FToolBarExtensionDelegate::CreateRaw(
			this, &FNansTimelineSystemToolbar::AddToolbarExtension
		)
	);
	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
}

void FNansTimelineSystemToolbar::Unregister()
{
	ToolbarExtender->RemoveExtension(Extension.ToSharedRef());
	Extension.Reset();
	ToolbarExtender.Reset();
}

void FNansTimelineSystemToolbar::MyButton_Clicked() const
{
	const TSharedRef<SWindow> TimelineSystemWindow = SNew(SWindow)
													 .Title(FText::FromString(TEXT("Timeline System Window")))
													 .ClientSize(FVector2D(800, 400))
													 .SupportsMaximize(false)
													 .SupportsMinimize(false);

	TimelineSystemWindow->SetContent(SNew(SWindowTimeline));
	
	IMainFrameModule& MainFrameModule =
		FModuleManager::LoadModuleChecked<IMainFrameModule>
		(TEXT("MainFrame"));
	if (MainFrameModule.GetParentWindow().IsValid())
	{
		FSlateApplication::Get().AddWindowAsNativeChild
		(
			TimelineSystemWindow, MainFrameModule.GetParentWindow()
			.ToSharedRef()
		);
	}
	else
	{
		FSlateApplication::Get().AddWindow(TimelineSystemWindow);
	}
}

void FNansTimelineSystemToolbar::AddToolbarExtension(FToolBarBuilder& builder) const
{
	const FSlateIcon IconBrush =
		FSlateIcon(
			FNansTimelineSystemStyle::GetStyleSetName(),
			"LevelEditor.TimelineSystemPanel",
			"LevelEditor.TimelineSystemPanel.Small"
		);
	builder.AddToolBarButton(
		FNansTimelineSystemCommands::Get().MyButton, NAME_None, FText::FromString("Timeline"),
		FText::FromString("Open the Timeline System panel overview"),
		IconBrush, NAME_None
	);
}
