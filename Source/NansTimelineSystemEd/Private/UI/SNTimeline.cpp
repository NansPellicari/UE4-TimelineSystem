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

#include "SNTimeline.h"

#include "SlateOptMacros.h"
#include "LogVisualizerStyle.h"
#include "Event/EventView.h"

#define LOCTEXT_NAMESPACE "NansTimelineSystemEd"

// NB: These have to be here until C++17 allows inline variables
// const ISlateStyle& Logger = FLogVisualizerStyle::Get();
// const FSlateBrush* FillImage = Logger.GetBrush("LogVisualizer.LogBar.EntryDefault");
const FSlateBrush* SNTimeline::FillImage = FEditorStyle::GetBrush("Profiler.LineGraphArea");
constexpr FColor SNTimeline::TimelineColor;
constexpr FColor SNTimeline::EventColor;
constexpr FColor SNTimeline::PreEventColor;
constexpr FColor SNTimeline::EventExpiredColor;
constexpr FColor SNTimeline::PreEventExpiredColor;
constexpr FColor SNTimeline::EventScheduledColor;
constexpr FColor SNTimeline::PreEventScheduledColor;
constexpr ESlateDrawEffect SNTimeline::DrawEffects;
constexpr float SNTimeline::TimelineHeight;
constexpr float SNTimeline::EventHeight;
constexpr float SNTimeline::UnitSecs;
constexpr float SNTimeline::MarginVertical;
constexpr float SNTimeline::PaddingHorizontal;

TMap<FName, FTimelineData> SNTimeline::TimelineRows;

bool FEventsRow::AddSlot(const FEventSlot& InSlot)
{
	bool bHasPosition = true;
	if (Slots.Num() > 0)
	{
		const FEventSlot& LastEvent = Slots.Last();
		const float RealOffset = InSlot.PreOffset > 0 ? InSlot.PreOffset : InSlot.Offset;
		bHasPosition = LastEvent.Offset + LastEvent.Size <= RealOffset && LastEvent.Event->GetDuration() > 0;
	}

	if (bHasPosition)
	{
		Slots.Add(InSlot);
	}

	return bHasPosition;
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SNTimeline::Construct(const FArguments& InArgs) {}

SNTimeline::~SNTimeline()
{
	if (CurrentTimelineName != NAME_None && TimelineRows.Contains(CurrentTimelineName))
	{
		TimelineRows.Remove(CurrentTimelineName);
	}
}

void SNTimeline::ChangeTimeline(UNTimelineManagerDecorator* Timeline)
{
	if (CurrentTimelineName != NAME_None && TimelineRows.Contains(CurrentTimelineName))
	{
		TimelineRows.Remove(CurrentTimelineName);
	}

	LastRowNum = -1;
	LastSlotNum = -1;

	if (IsValid(Timeline))
	{
		CurrentTimeline = Timeline;
		CurrentTimelineName = CurrentTimeline->GetLabel();
		TimelineRows.Add(CurrentTimelineName, FTimelineData());
	}
}

FVector2D SNTimeline::ComputeDesiredSize(float) const
{
	float YSize = 4.f;
	float XSize = 500.f;
	const bool bIsDecoTimeline = IsValid(CurrentTimeline) && !CurrentTimeline->HasAnyFlags(
									 RF_BeginDestroyed | RF_FinishDestroyed
								 );
	const bool bIsTimeline = bIsDecoTimeline && CurrentTimeline->GetTimeline().IsValid();
	const float Time = bIsTimeline ? CurrentTimeline->GetCurrentTime() : 0;

	if (bIsTimeline && TimelineRows.Contains(CurrentTimelineName))
	{
		YSize += (EventHeight + MarginVertical) * TimelineRows[CurrentTimelineName].MaxRows;
		XSize = TimelineRows[CurrentTimelineName].MaxTime > Time
					? TimelineRows[CurrentTimelineName].MaxTime * UnitSecs
					: Time * UnitSecs;
		XSize = FMath::Max(XSize, 500.f);
	}
	return FVector2D(XSize, YSize);
}

FReply SNTimeline::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!TimelineRows.Contains(CurrentTimelineName) || TimelineRows[CurrentTimelineName].Rows.Num() <= 0)
	{
		return FReply::Unhandled();
	}

	const FVector2D CursorPos = MyGeometry.AbsoluteToLocal(MouseEvent.GetLastScreenSpacePosition());
	int32 RowNum = 0;
	int32 SlotNum = 0;

	int32 CurrentSlotNum = -1;
	int32 CurrentRowNum = -1;

	for (const FEventsRow& Row : TimelineRows[CurrentTimelineName].Rows)
	{
		const float RowYMin = TimelineHeight + RowNum * (EventHeight + MarginVertical);
		const float RowYMax = RowYMin + EventHeight;

		if (CursorPos.Y < RowYMin)
		{
			break;
		}

		if (CursorPos.Y > RowYMax)
		{
			RowNum++;
			continue;
		}

		for (const FEventSlot& Slot : Row.Slots)
		{
			const float RowXMin = Slot.PreOffset > 0 ? Slot.PreOffset : Slot.Offset;
			const float RowXMax = RowXMin + Slot.PreSize + Slot.Size;

			if (CursorPos.X > + RowXMin && CursorPos.X <= RowXMax)
			{
				CurrentSlotNum = SlotNum;
				CurrentRowNum = RowNum;
				break;
			}
			SlotNum++;
		}
		RowNum++;
	}

	if (CurrentRowNum > -1 && CurrentSlotNum > -1)
	{
		if (CurrentRowNum != LastRowNum || CurrentSlotNum != LastSlotNum)
		{
			LastRowNum = CurrentRowNum;
			LastSlotNum = CurrentSlotNum;
			const UNEventView* EventFound = TimelineRows[CurrentTimelineName].Rows[LastRowNum].Slots[LastSlotNum].Event;
			FString TooltipBuilder;
			TooltipBuilder += FString::Format(TEXT("Name: {0}"), {EventFound->GetEventLabel().ToString()});
			if (EventFound->IsExpired())
			{
				TooltipBuilder += TEXT(" (expired)");
			}
			TooltipBuilder += FString::Format(TEXT("\nAttached at: {0}"), {EventFound->GetAttachedTime()});
			TooltipBuilder += FString::Format(TEXT("\nStarted at: {0}"), {EventFound->GetStartedAt()});
			TooltipBuilder += FString::Format(TEXT("\nDuration: {0}"), {EventFound->GetDuration()});
			TooltipBuilder += FString::Format(TEXT("\nDelay: {0}"), {EventFound->GetDelay()});
			TooltipBuilder += FString::Format(TEXT("\nUId: {0}"), {EventFound->GetUID()});
			SetToolTipText(FText::AsCultureInvariant(TooltipBuilder));
		}
		return FReply::Handled();
	}

	LastRowNum = -1;
	LastSlotNum = -1;
	SetToolTipText(FText::AsCultureInvariant(TEXT("")));
	return FReply::Unhandled();
}

void SNTimeline::CreateSlot(const float EndPos, const UNEventView* Event, TArray<FEventsRow>& Rows) const
{
	float EventStartedAt = Event->GetStartedAt() >= 0.f ? UnitSecs * Event->GetStartedAt() : -1.f;
	// This for events that are forward the end of the current timeline (in the future),
	// otherwise they will not have a width cause it is calculate with the end position of the timeline bar.
	float EventWidth = EventStartedAt >= 0 ? EndPos - EventStartedAt : 10.f;
	FColor Color = EventColor;
	FColor PreColor = PreEventColor;

	if (Event->GetStartedAt() <= 0)
	{
		Color = EventScheduledColor;
		PreColor = PreEventScheduledColor;
	}

	if (Event->IsExpired())
	{
		Color = EventExpiredColor;
		PreColor = PreEventExpiredColor;
	}

	FEventSlot Slot(Event);

	if (Event->GetDelay() > 0)
	{
		const float DelayStartedAt = Event->GetAttachedTime() * UnitSecs;
		EventStartedAt = (Event->GetAttachedTime() + Event->GetDelay()) * UnitSecs;
		const float DelayWidth = EventStartedAt - DelayStartedAt;

		Slot.PreColor = PreColor;
		Slot.PreOffset = DelayStartedAt;
		Slot.PreSize = DelayWidth;
	}

	if (Event->GetDuration() > 0)
	{
		EventWidth = UnitSecs * Event->GetDuration();
	}

	Slot.Color = Color;
	Slot.Offset = EventStartedAt;
	Slot.Size = EventWidth;
	bool bIsInRow = false;

	// This to allow drawing events in the future
	{
		const float EventEndedAt = (EventStartedAt + EventWidth) / UnitSecs;
		FTimelineData& TimelineData = TimelineRows[CurrentTimelineName];
		TimelineData.MaxTime = TimelineData.MaxTime < EventEndedAt
								   ? EventEndedAt
								   : TimelineData.MaxTime;
	}

	for (FEventsRow& Row : Rows)
	{
		if (Row.AddSlot(Slot))
		{
			bIsInRow = true;
			break;
		}
	}

	if (!bIsInRow)
	{
		FEventsRow NewRow = FEventsRow();
		NewRow.AddSlot(Slot);
		Rows.Add(NewRow);
	}
}

int32 SNTimeline::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
	FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
	bool bParentEnabled) const
{
	int32 RetLayerId = LayerId;
	if (GEditor->PlayWorld == nullptr || !IsValid(CurrentTimeline) || !CurrentTimeline->GetTimeline().IsValid()
		|| !TimelineRows.Contains(CurrentTimelineName))
	{
		return RetLayerId;
	}

	const float EndPos = CurrentTimeline->GetCurrentTime() * UnitSecs;
	float YPos = 0;
	float NewYPos = TimelineHeight;

	if (EndPos <= 0)
	{
		return RetLayerId;
	}
	const float BarWidth = EndPos;

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		++RetLayerId,
		AllottedGeometry.ToPaintGeometry(
			FVector2D(0.f, YPos),
			FVector2D(BarWidth, NewYPos)
		),
		FillImage,
		DrawEffects,
		TimelineColor
	);
	YPos += NewYPos + MarginVertical;
	NewYPos = EventHeight;

	const TArray<UNEventView*> ExpiredEvents = CurrentTimeline->GetExpiredEventViews();

	FTimelineData& TimelineData = TimelineRows[CurrentTimelineName];
	TimelineData.Rows.Init(FEventsRow(), 6);

	for (const UNEventView* Event : ExpiredEvents)
	{
		CreateSlot(EndPos, Event, TimelineData.Rows);
	}

	const TArray<UNEventView*> Events = CurrentTimeline->GetEventViews();

	for (const UNEventView* Event : Events)
	{
		CreateSlot(EndPos, Event, TimelineData.Rows);
	}

	for (FEventsRow& Row : TimelineData.Rows)
	{
		if (Row.Slots.Num() > 0)
		{
			for (const FEventSlot& Slot : Row.Slots)
			{
				bool bHasPre = false;
				// int32 LayerId = ++RetLayerId;
				if (Slot.PreSize > 0.f)
				{
					bHasPre = true;
					FSlateDrawElement::MakeBox(
						OutDrawElements,
						++RetLayerId,
						AllottedGeometry.ToPaintGeometry(
							FVector2D(Slot.PreOffset + PaddingHorizontal, YPos),
							FVector2D(Slot.PreSize, EventHeight)
						),
						FillImage,
						DrawEffects,
						Slot.PreColor
					);
				}

				FSlateDrawElement::MakeBox(
					OutDrawElements,
					++RetLayerId,
					AllottedGeometry.ToPaintGeometry(
						FVector2D(Slot.Offset + (bHasPre ? 0.f : PaddingHorizontal), YPos),
						FVector2D(Slot.Size - PaddingHorizontal, EventHeight)
					),
					FillImage,
					DrawEffects,
					Slot.Color
				);
			}
		}

		YPos += NewYPos + MarginVertical;
		NewYPos = EventHeight;
	}

	TimelineRows[CurrentTimelineName].MaxRows = TimelineData.Rows.Num();

	return RetLayerId;
}

UNTimelineManagerDecorator* SNTimeline::GetCurrentTimeline() const { return CurrentTimeline; }

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
