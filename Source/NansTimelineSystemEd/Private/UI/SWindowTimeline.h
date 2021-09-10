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

#include "CoreMinimal.h"
#include "Manager/TimelineManagerDecorator.h"

#include "Widgets/SCompoundWidget.h"

class SScrollBox;
class ITableRow;
class STableViewBase;
class SNTimeline;

/**
 * The main window that embedded the timeline widget (SNTimeline) and the timelines selector.
 */
class NANSTIMELINESYSTEMED_API SWindowTimeline : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWindowTimeline) {}
		SLATE_ARGUMENT(TSharedPtr<SDockTab>, ParentTab)
	SLATE_END_ARGS()

	virtual ~SWindowTimeline();

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	/** Display text depending on the context. */
	FText BuildText() const;
private:
	/**
	 * Get the size desired for the scrollbar using the timeline panel width.
	 * @param Orientation - Get the size depending on this orientation (Width or Height).
	 */
	float GetScrollBarSize(const EOrientation& Orientation) const;

	/**
	 * Get the timeline manager depending on the timeline name chosen.
	 * @return nullptr if no game world or no name has been chosen
	 */
	UNTimelineManagerDecorator* GetTimelineManager() const;

	/** Manage the choice of user */
	void OnTimelineChanged(TSharedPtr<FName> NewValue, ESelectInfo::Type SelectInfo);

	/** Generates the display name of the selected timeline */
	FText CreateTimelineNamesComboBoxContent() const;

	/** Generates a list of names from the configured timelines */
	TSharedRef<SWidget> OnGenerateTimelineNamesComboBox(TSharedPtr<FName> InItem) const;

	/** Listener of the FWorldDelegates::OnStartGameInstance to notify the timeline widget.  */
	void OnGameInstanceStart(UGameInstance* GI);

	/** List of timelines names configured by user in plugin's config.  */
	TArray<TSharedPtr<FName>> TimelineNames;
	/** Timeline panel displaying events and time */
	TSharedPtr<SNTimeline> TimelineWidget;
	/** Horizontal scroll bar, used for scrolling timeline graphs. */
	TSharedPtr<SScrollBar> HorizontalScrollBar;
	/** Vertical scroll bar, used for scrolling timeline graphs. */
	TSharedPtr<SScrollBar> VerticalScrollBar;
	/** The chosen timeline's name. */
	TSharedPtr<FName> CurrentTimeline = MakeShared<FName>(NAME_None);
	/** The combobox widget of the timelines choices */
	TSharedPtr<SComboBox<TSharedPtr<FName>>> TimelineComboBox;

	TSharedPtr<SDockTab> ParentTabPtr;
};
