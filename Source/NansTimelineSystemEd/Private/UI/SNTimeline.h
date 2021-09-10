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

#include "Config/TimelineConfig.h"

/** All details about an event to draw */
struct FEventSlot
{
	FEventSlot(const UNEventBase* InEvent) : Event(InEvent) {}
	/** Represents the moment this event has been attached if it has a delay. */
	float PreOffset = 0.f;
	/** If there is, the size of the delay. */
	float PreSize = 0.f;
	/** Color of the delay. */
	FColor PreColor;
	/** Represents the moment this event start to play. */
	float Offset = 0.f;
	/** Represents the event duration. */
	float Size = 0.f;
	/** Color of the event. */
	FColor Color;
	/** Event associated to this slot. */
	const UNEventBase* Event;
};

/**
* Saved data when timeline are paint.
* @see SNTimeline::OnPaint()
*/
struct FEventsRow
{
	/** The slots saved in this row. */
	TArray<FEventSlot> Slots;
	/**
	 * Try to add the slot.
	 * @return true if added or false if 1. , 2. no places available for it 
	 */
	bool AddSlot(FEventSlot&& InSlot);
	/** Checks if this event has been already added in any slot. */
	FEventSlot* IsEventAdded(const UNEventBase* Event);
};

/**
 * Saved data when timeline are paint.
 * @see SNTimeline::OnPaint()
 */
struct FTimelineData
{
	/** The rows where event's slot (FEventSlot) are saved. */
	TArray<FEventsRow> Rows;
	/** The current timeline time + events in the future. */
	float MaxTime = 0.f;
	/** Used to know if it can be destroyed. */
	int32 Owners = 0;
	/** Checks if this event has been already added in any row's slot. */
	FEventSlot* IsEventAdded(const UNEventBase* Event);
	/** Try to put this slot in an available row (FEventsRow) or create a new one if not already added in a row. */
	void AddSlot(FEventSlot&& Slot);
};

/** This widget will draw timeline and events thanks to its UNTimelineManagerDecorator passed in. */
class NANSTIMELINESYSTEMED_API SNTimeline : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SNTimeline) {}
		SLATE_ARGUMENT(UNTimelineManagerDecorator*, Timeline)
	SLATE_END_ARGS()

	/**
	 * Constructs this widget with InArgs and listen
	 * FWorldDelegates::OnWorldBeginTearDown + FWorldDelegates::OnStartGameInstance
	 * to change bShouldComputeSize values. 
	 */
	void Construct(const FArguments& InArgs);

	/** Clear TimelineRows if no other owners */
	virtual ~SNTimeline();

	/** Will change the current timeline */
	void ChangeTimeline(UNTimelineManagerDecorator* Timeline);

	/** Compute the widget side depending on events and timeline data. */
	virtual FVector2D ComputeDesiredSize(float) const override;
	/** Manage tooltip to display event data. */
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	/**
	 * Create a slot to draw (@see SNTimeline::OnPaint()) based on event data.
	 */
	void CreateSlot(float EndPos, const UNEventBase* Event) const;

	/** Will paint each event slots and timeline. */
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled) const override;
	/** Get the current timeline, can returns nullptr. */
	UNTimelineManagerDecorator* GetCurrentTimeline() const;

private:
	/** The timeline the user chose for this panel. */
	UNTimelineManagerDecorator* CurrentTimeline = nullptr;
	/** The name of the current timeline, created to simplify the usage of TimelineRows. */
	FName CurrentTimelineName = NAME_None;
	/**
	 * This is used for tooltip when mouse move.
	 * @see SNTimeline::OnMouseMove()
	 */
	int32 CurrentSlotNum = -1;
	/**
	* This is used for tooltip when mouse move.
	* @see SNTimeline::OnMouseMove()
	*/
	int32 CurrentRowNum = -1;

	/** @see SNTimeline::Construct() */
	FDelegateHandle DelegateStartGameHandle;
	/** @see SNTimeline::Construct() */
	FDelegateHandle DelegateEndGameHandle;
	/** @see SNTimeline::Construct() */
	FDelegateHandle DelegateLoadMapHandle;

	/**
	 * This allows to share data:
	 * - saved or modified in const methods
	 * - between windows instances
	 * @see SNTimeline::OnPaint()
	 */
	static TMap<FName, FTimelineData> TimelineRows;

	/**
	 * Informs SNTimeline::ComputeDesiredSize() if it should compute.
	 * Allows to be called only when a game is playing to avoid getting non-valid timeline for computation.
	 */
	bool bShouldComputeSize = true;

	// Constants
	static const FSlateBrush* FillImage;
	static constexpr FColor TimelineColor = FColor(140, 255, 255, 255);
	static constexpr ESlateDrawEffect DrawEffects = ESlateDrawEffect::None;
	static constexpr float TimelineHeight = 2.0f;
	static constexpr float EventHeight = 10.f;
	static constexpr float UnitSecs = 5.f;
	static constexpr float MarginVertical = 2.f;
	static constexpr float PaddingHorizontal = 1.f;
};
