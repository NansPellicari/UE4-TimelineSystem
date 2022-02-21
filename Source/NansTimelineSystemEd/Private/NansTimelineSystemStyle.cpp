// Copyright Nans Pellicari, 2021

#include "NansTimelineSystemStyle.h"

#include "Brushes/SlateImageBrush.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

TSharedPtr<FSlateStyleSet> FNansTimelineSystemStyle::StyleInstance = nullptr;

void FNansTimelineSystemStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FNansTimelineSystemStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FNansTimelineSystemStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("NansTimelineSystemStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )

const FVector2D Icon128x128(128.0f, 128.0f);
const FVector2D Icon64x64(64.0f, 64.0f);
const FVector2D Icon40x40(40.0f, 40.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon12x12(12.0f, 12.0f);
TSharedRef< FSlateStyleSet > FNansTimelineSystemStyle::Create()
{
	TSharedRef<FSlateStyleSet> Style = MakeShared<FSlateStyleSet>("NansTimelineSystemStyle");

	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("NansTimelineSystem"));
	check(Plugin.IsValid());
	if (Plugin.IsValid())
	{
		Style->SetContentRoot(FPaths::Combine(Plugin->GetBaseDir(), TEXT("Resources/AssetIcons")));
	}

	Style->Set("ClassIcon.NEventBase", new IMAGE_BRUSH("NEvent_x16", Icon16x16));
	Style->Set("ClassIcon.NEventBaseBlueprint", new IMAGE_BRUSH("NEvent_x16", Icon16x16));
	Style->Set("ClassThumbnail.NEventBase", new IMAGE_BRUSH("NEvent_x64", Icon64x64));
	Style->Set("ClassThumbnail.NEventBaseBlueprint", new IMAGE_BRUSH("NEvent_x64", Icon64x64));
	Style->Set("LevelEditor.TimelineSystemPanel", new IMAGE_BRUSH("NEvent_x64", Icon40x40));
	Style->Set("LevelEditor.TimelineSystemPanel.Small", new IMAGE_BRUSH("NEvent_x64", Icon20x20));

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH

const ISlateStyle& FNansTimelineSystemStyle::Get()
{
	return *StyleInstance;
}
