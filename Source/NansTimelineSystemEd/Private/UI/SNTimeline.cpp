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
const FSlateBrush* SNTimeline::FillImage = FEditorStyle::GetBrush("Profiler.LineGraphArea");
constexpr FColor SNTimeline::TimelineColor;
constexpr ESlateDrawEffect SNTimeline::DrawEffects;
constexpr float SNTimeline::TimelineHeight;
constexpr float SNTimeline::EventHeight;
constexpr float SNTimeline::UnitSecs;
constexpr float SNTimeline::MarginVertical;
constexpr float SNTimeline::PaddingHorizontal;

TMap<FName, FTimelineData> SNTimeline::TimelineRows;

bool FEventsRow::AddSlot(FEventSlot&& InSlot)
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

FEventSlot* FEventsRow::IsEventAdded(const UNEventView* Event)
{
	FEventSlot* EventSlot = nullptr;
	for (FEventSlot& Slot : Slots)
	{
		if (Event == Slot.Event)
		{
			EventSlot = &Slot;
		}
	}
	return EventSlot;
}

FEventSlot* FTimelineData::IsEventAdded(const UNEventView* Event)
{
	FEventSlot* EventSlot = nullptr;
	for (FEventsRow& Row : Rows)
	{
		EventSlot = Row.IsEventAdded(Event);
		if (EventSlot != nullptr) break;
	}
	return EventSlot;
}

void FTimelineData::AddSlot(FEventSlot&& Slot)
{
	bool bIsInRow = false;

	if (IsEventAdded(Slot.Event) != nullptr)
	{
		return;
	}

	for (FEventsRow& Row : Rows)
	{
		if (Row.AddSlot(MoveTemp(Slot)))
		{
			bIsInRow = true;
			break;
		}
	}

	if (!bIsInRow)
	{
		FEventsRow NewRow = FEventsRow();
		NewRow.AddSlot(MoveTemp(Slot));
		Rows.Add(NewRow);
	}
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SNTimeline::Construct(const FArguments& InArgs) {}

SNTimeline::~SNTimeline()
{
	if (CurrentTimelineName != NAME_None && TimelineRows.Contains(CurrentTimelineName))
	{
		if (TimelineRows[CurrentTimelineName].Owners == 1)
		{
			TimelineRows.Remove(CurrentTimelineName);
		}
		else
		{
			TimelineRows[CurrentTimelineName].Owners--;
		}
	}
}

void SNTimeline::ChangeTimeline(UNTimelineManagerDecorator* Timeline)
{
	if (CurrentTimelineName != NAME_None
		&& TimelineRows.Contains(CurrentTimelineName))
	{
		if (TimelineRows[CurrentTimelineName].Owners == 1)
		{
			TimelineRows.Remove(CurrentTimelineName);
		}
		else
		{
			TimelineRows[CurrentTimelineName].Owners--;
		}
	}

	CurrentRowNum = -1;
	CurrentSlotNum = -1;

	if (IsValid(Timeline))
	{
		CurrentTimeline = Timeline;
		CurrentTimelineName = CurrentTimeline->GetLabel();
		if (!TimelineRows.Contains(CurrentTimelineName))
		{
			TimelineRows.Add(CurrentTimelineName, FTimelineData());
		}
		TimelineRows[CurrentTimelineName].Owners++;
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
		YSize += (EventHeight + MarginVertical) * TimelineRows[CurrentTimelineName].Rows.Num();
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

	int32 ChosenSlotNum = -1;
	int32 ChosenRowNum = -1;

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
				ChosenSlotNum = SlotNum;
				ChosenRowNum = RowNum;
				break;
			}
			SlotNum++;
		}
		RowNum++;
	}

	if (ChosenRowNum > -1 && ChosenSlotNum > -1)
	{
		if (ChosenRowNum != CurrentRowNum || ChosenSlotNum != CurrentSlotNum)
		{
			CurrentRowNum = ChosenRowNum;
			CurrentSlotNum = ChosenSlotNum;
			const UNEventView* EventFound = TimelineRows[CurrentTimelineName].Rows[CurrentRowNum].Slots[CurrentSlotNum].
				Event;
			SetToolTipText(FText::AsCultureInvariant(EventFound->GetDebugTooltipText()));
		}
		return FReply::Handled();
	}

	CurrentRowNum = -1;
	CurrentSlotNum = -1;
	SetToolTipText(FText::AsCultureInvariant(TEXT("")));
	return FReply::Unhandled();
}

void SNTimeline::CreateSlot(const float EndPos, const UNEventView* Event) const
{
	FEventSlot Slot(Event);
	float EventStartedAt = Event->GetStartedAt() >= 0.f ? UnitSecs * Event->GetStartedAt() : -1.f;
	// This for events that are forward the end of the current timeline (in the future),
	// otherwise they will not have a width cause it is calculate with the end position of the timeline bar.
	Slot.Size = EventStartedAt >= 0 ? EndPos - EventStartedAt : 10.f;
	if (Event->GetDuration() > 0)
	{
		Slot.Size = UnitSecs * Event->GetDuration();
	}

	FColor Color = Event->GetDebugColor();
	FColor PreColor = Color.WithAlpha(Color.A / 2);

	if (Event->GetStartedAt() <= 0)
	{
		Color = Color.WithAlpha(Color.A / 1.5);
		PreColor = PreColor.WithAlpha(PreColor.A / 1.5);
	}

	if (Event->IsExpired())
	{
		constexpr float Alpha = 0.6f;
		// Lerp to Gray
		Color = (FLinearColor(Color) + Alpha * (FLinearColor::Gray - Color)).ToFColor(false);
		PreColor = (FLinearColor(PreColor) + Alpha * (FLinearColor::Gray - PreColor)).ToFColor(false);;
	}

	if (Event->GetDelay() > 0)
	{
		const float DelayStartedAt = Event->GetAttachedTime() * UnitSecs;
		EventStartedAt = (Event->GetAttachedTime() + Event->GetDelay()) * UnitSecs;
		const float DelayWidth = EventStartedAt - DelayStartedAt;

		Slot.PreColor = PreColor;
		Slot.PreOffset = DelayStartedAt;
		Slot.PreSize = DelayWidth;
	}

	Slot.Color = Color;
	Slot.Offset = EventStartedAt;

	FTimelineData& TimelineData = TimelineRows[CurrentTimelineName];

	// This to allow drawing events in the future
	{
		const float EventEndedAt = (EventStartedAt + Slot.Size) / UnitSecs;
		TimelineData.MaxTime = TimelineData.MaxTime < EventEndedAt
								   ? EventEndedAt
								   : TimelineData.MaxTime;
	}

	TimelineData.AddSlot(MoveTemp(Slot));
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
	const TArray<UNEventView*> Events = CurrentTimeline->GetEventViews();

	FTimelineData& TimelineData = TimelineRows[CurrentTimelineName];
	TimelineData.Rows.Init(FEventsRow(), 6);

	for (const UNEventView* Event : ExpiredEvents)
	{
		CreateSlot(EndPos, Event);
	}

	for (const UNEventView* Event : Events)
	{
		CreateSlot(EndPos, Event);
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

	return RetLayerId;
}

UNTimelineManagerDecorator* SNTimeline::GetCurrentTimeline() const { return CurrentTimeline; }

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
