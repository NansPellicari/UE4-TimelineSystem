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

#include "SWindowTimeline.h"

#include "SlateOptMacros.h"
#include "SNTimeline.h"
#include "TimelineGameSubsystem.h"
#include "Config/TimelineConfig.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Views/STableRow.h"

#define LOCTEXT_NAMESPACE "NansTimelineSystemEd"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SWindowTimeline::~SWindowTimeline()
{
	FWorldDelegates::OnStartGameInstance.RemoveAll(this);
}

void SWindowTimeline::Construct(const FArguments& InArgs)
{
	TArray<FConfiguredTimelineConf> Timelines;
	UNTimelineConfig::GetConfigs(Timelines);
	for (const FConfiguredTimelineConf& TimelineConf : Timelines)
	{
		TimelineNames.Add(MakeShared<FName>(TimelineConf.Name));
	}

	HorizontalScrollBar = SNew(SScrollBar)
						  .Orientation(Orient_Horizontal)
						  .AlwaysShowScrollbar(true)
						  .Visibility(EVisibility::Visible)
						  .Thickness(FVector2D(12.0f, 12.0f));

	VerticalScrollBar = SNew(SScrollBar)
						.Orientation(Orient_Vertical)
						.AlwaysShowScrollbar(true)
						.Visibility(EVisibility::Visible)
						.Thickness(FVector2D(12.0f, 12.0f));
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot() // The buttons row
		.HAlign(HAlign_Center).VAlign(VAlign_Top).AutoHeight().Padding(20.f)
		[
			SNew(SListView<TSharedPtr<FName>>)
			// .ItemHeight(24)
			.SelectionMode(ESelectionMode::Single)
			.ListItemsSource(&TimelineNames)
			.OnGenerateRow(this, &SWindowTimeline::OnGenerateRowForList)
			.OnSelectionChanged(this, &SWindowTimeline::OnTimelineChanged)
		]
		+ SVerticalBox::Slot() // The chosen timeline's name
		.HAlign(HAlign_Center).VAlign(VAlign_Top).AutoHeight().Padding(20.f, 10.f)
		[
			SNew(STextBlock)
			.Text(FText::FromName(*CurrentTimeline))
			.Text_Raw(this, &SWindowTimeline::BuildText)
			.Margin(FMargin(5.f, 0))
		]
		+ SVerticalBox::Slot() // The chosen timeline's panel
		.HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(10.f, 5.f, 10.f, 0.f)
		[
			// This allow to put the vertical scroll bar aside and
			// let it has the same full height of the timeline panel. 
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(100.f).VAlign(VAlign_Fill).HAlign(HAlign_Fill)
			[
				SNew(SScrollBox)
				.Orientation(Orient_Vertical)
				.ExternalScrollbar(VerticalScrollBar)
				+ SScrollBox::Slot()
				.HAlign(HAlign_Left)
				[
					SNew(SScrollBox)
					.Orientation(Orient_Horizontal)
					.ExternalScrollbar(HorizontalScrollBar)
					+ SScrollBox::Slot()
					[
						SNew(SBox)
						.Padding(FMargin(0, 0, 0, 0))
						.HAlign(HAlign_Left).VAlign(VAlign_Fill)
						[
							SAssignNew(TimelineWidget, SNTimeline)
						]
					]
				]
			]
			+ SHorizontalBox::Slot()
			.AutoWidth().HAlign(HAlign_Right)
			[
				VerticalScrollBar.ToSharedRef()
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight().Padding(20.f, 0.f)
		[
			HorizontalScrollBar.ToSharedRef()
		]
	];

	HorizontalScrollBar->SetState(0.0f, 1.0f);
	VerticalScrollBar->SetState(0.0f, 1.0f);
	FWorldDelegates::OnStartGameInstance.AddRaw(this, &SWindowTimeline::OnGameInstanceStart);
}

void SWindowTimeline::OnGameInstanceStart(UGameInstance* GI)
{
	if (GEditor->PlayWorld != nullptr && GEditor->PlayWorld->IsGameWorld())
	{
		OnTimelineChanged(CurrentTimeline, ESelectInfo::Direct);
	}
}

FText SWindowTimeline::BuildText() const
{
	const UWorld* World = GEditor->PlayWorld;
	const UNTimelineManagerDecorator* Timeline = GetTimelineManager();
	FText Text;

	if (!World)
	{
		Text = FText::Format(
			LOCTEXT("NoGameWorld", "Need to play the game to debug {0} timeline"), FText::FromName(*CurrentTimeline)
		);
	}
	else
	{
		FString Time = TEXT("");
		if (IsValid(Timeline))
		{
			FNumberFormattingOptions Opts;
			Opts.MinimumFractionalDigits = 2;
			Opts.MaximumFractionalDigits = 2;
			Time = FText::Format(
				LOCTEXT("CanDebugTimelineTime", ", ({0}s)"), FText::AsNumber(Timeline->GetCurrentTime(), &Opts)
			).ToString();
		}
		Text = FText::Format(
			LOCTEXT("CanDebugTimeline", "Debugging {0} timeline{1}"), FText::FromName(*CurrentTimeline),
			FText::FromString(*Time)
		);
	}
	return Text;
}

TSharedRef<ITableRow> SWindowTimeline::OnGenerateRowForList(TSharedPtr<FName> InItem,
	const TSharedRef<STableViewBase>& OwnerTable) const
{
	return SNew(STableRow<TSharedPtr<FName>>, OwnerTable)
		   [
			   SNew(STextBlock).Text(FText::FromName(*InItem))
		   ];
}

float SWindowTimeline::GetScrollBarSize(const EOrientation& Orientation) const
{
	float ThumbSizeFraction = 1.f;

	if (IsValid(TimelineWidget->GetCurrentTimeline()))
	{
		const FGeometry Geometry = TimelineWidget->GetCachedGeometry();
		const FVector2D LocalSize = Geometry.GetLocalSize();
		const FVector2D SizeWidget = TimelineWidget->ComputeDesiredSize(0.f);
		if (Orientation == Orient_Horizontal)
		{
			ThumbSizeFraction = FMath::Min(LocalSize.X / SizeWidget.X, 1.0f);
		}
		else
		{
			ThumbSizeFraction = FMath::Min(LocalSize.Y / SizeWidget.Y, 1.0f);
		}
	}
	return ThumbSizeFraction;
}

UNTimelineManagerDecorator* SWindowTimeline::GetTimelineManager() const
{
	if (*CurrentTimeline == NAME_None)
	{
		return nullptr;
	}
	const UWorld* World = GEditor->PlayWorld;
	if (!IsValid(World))
	{
		return nullptr;
	}

	const UGameInstance* GI = World->GetGameInstance();
	UTimelineGameSubsystem* MySubsystem = GI->GetSubsystem<UTimelineGameSubsystem>();

	check(MySubsystem != nullptr);

	return MySubsystem->GetTimeline(*CurrentTimeline);
}

void SWindowTimeline::OnTimelineChanged(TSharedPtr<FName> NewValue, ESelectInfo::Type SelectInfo)
{
	const bool bIsNotAccepted = SelectInfo == ESelectInfo::Direct ? false : CurrentTimeline == NewValue;

	if (!NewValue.IsValid() || bIsNotAccepted)
	{
		return;
	}

	CurrentTimeline = NewValue;
	UNTimelineManagerDecorator* Timeline = GetTimelineManager();

	if (TimelineWidget.IsValid())
	{
		TimelineWidget->ChangeTimeline(Timeline);

		const float ThumbSizeFractionH = GetScrollBarSize(Orient_Horizontal);
		HorizontalScrollBar->SetState(0.0f, ThumbSizeFractionH);

		const float ThumbSizeFractionV = GetScrollBarSize(Orient_Vertical);
		VerticalScrollBar->SetState(0.0f, ThumbSizeFractionV);
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
