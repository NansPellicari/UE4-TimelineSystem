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

struct FEventSlot
{
	FEventSlot(const UNEventView* InEvent) : Event(InEvent) {}
	float PreOffset = 0.f;
	float PreSize = 0.f;
	FColor PreColor;
	float Offset = 0.f;
	float Size = 0.f;
	FColor Color;
	const UNEventView* Event;
};

struct FEventsRow
{
	TArray<FEventSlot> Slots;
	bool AddSlot(const FEventSlot& InSlot);
};

struct FTimelineData
{
	float MaxRows = 0.f;
	TArray<FEventsRow> Rows;
	float MaxTime = 0.f;
};

/**
 * 
 */
class NANSTIMELINESYSTEMED_API SNTimeline : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SNTimeline) {}
		SLATE_ARGUMENT(UNTimelineManagerDecorator*, Timeline)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual ~SNTimeline();

	void ChangeTimeline(UNTimelineManagerDecorator* Timeline);

	virtual FVector2D ComputeDesiredSize(float) const override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void CreateSlot(float EndPos, const UNEventView* Event, TArray<FEventsRow>& Rows) const;

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled) const override;
	UNTimelineManagerDecorator* GetCurrentTimeline() const;

private:
	UNTimelineManagerDecorator* CurrentTimeline = nullptr;
	FName CurrentTimelineName = NAME_None;
	int32 LastSlotNum = -1;
	int32 LastRowNum = -1;
	static const FSlateBrush* FillImage;
	static constexpr FColor TimelineColor = FColor(140, 255, 255, 255);
	static constexpr ESlateDrawEffect DrawEffects = ESlateDrawEffect::None;
	static constexpr float TimelineHeight = 2.0f;
	static constexpr float EventHeight = 10.f;
	static constexpr float UnitSecs = 5.f;
	static constexpr float MarginVertical = 2.f;
	static constexpr float PaddingHorizontal = 1.f;
	static TMap<FName, FTimelineData> TimelineRows;
};
