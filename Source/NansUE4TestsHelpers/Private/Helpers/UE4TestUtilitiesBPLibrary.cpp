// Copyright Nans Pellicari, 2021

#include "Helpers/UE4TestUtilitiesBPLibrary.h"
#include "Engine.h"
#include "UMG/Public/Blueprint/UserWidget.h"


UNUE4TestUtilitiesBPLibrary::UNUE4TestUtilitiesBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {}

/**
 * This was inspired by this https://forums.unrealengine.com/development-discussion/c-gameplay-programming/35579-how-to-inject-simulate-mouse-clicks
 */
void UNUE4TestUtilitiesBPLibrary::TestUtilitiesClick(UWidget* Widget, bool& bSuccess, ETestUtilitiesMouseClick ClickBtn)
{
	FViewport* Viewport = GEngine->GameViewport->Viewport;
	FViewportClient* ViewportClient = Viewport->GetClient();
	if (!IsValid(Widget))
	{
		UE_LOG(LogTemp, Error, TEXT("%s Can't use this function on a NULL widget"), ANSI_TO_TCHAR(__FUNCTION__));
		return;
	}

	const FVector2D Pos = Widget->GetCachedGeometry().GetAbsolutePosition() + (
							  Widget->GetCachedGeometry().GetLocalSize() / 2.0f);

	const FKey MouseLMB = ClickBtn == ETestUtilitiesMouseClick::LEFT ? EKeys::LeftMouseButton : EKeys::RightMouseButton;
	ViewportClient->InputKey(Viewport, 0, MouseLMB, IE_Pressed);

	//Get our slate application
	FSlateApplication& SlateApp = FSlateApplication::Get();

	const TSharedPtr<FGenericWindow> GenWindow;

	//create a pointer event
	const FPointerEvent MouseDownEvent(
		0,
		SlateApp.CursorPointerIndex,
		Pos,
		SlateApp.GetLastCursorPos(),
		SlateApp.GetPressedMouseButtons(),
		MouseLMB,
		0,
		SlateApp.GetPlatformApplication()->GetModifierKeys()
	);
	//send the mouse event to the slate handler
	bSuccess = SlateApp.ProcessMouseButtonDownEvent(GenWindow, MouseDownEvent);
	bSuccess = bSuccess && SlateApp.ProcessMouseButtonUpEvent(MouseDownEvent);
}

void UNUE4TestUtilitiesBPLibrary::TestUtilitiesTouch(UWidget* Widget, bool& bSuccess)
{
	if (!IsValid(Widget))
	{
		UE_LOG(LogTemp, Error, TEXT("%s Can't use this function on a NULL widget"), ANSI_TO_TCHAR(__FUNCTION__));
		return;
	}

	FVector2D Pos = Widget->GetCachedGeometry().GetAbsolutePosition() + (
						Widget->GetCachedGeometry().GetLocalSize() / 2.0f);

	// ViewportClient->InputTouch(Viewport, 0, 0, ETouchType::Began, IE_Pressed);

	//Get our slate application
	FSlateApplication& SlateApp = FSlateApplication::Get();


	const TSharedPtr<FGenericWindow> GenWindow;

	const FPointerEvent TouchEventBegan(
		0,
		SlateApp.CursorPointerIndex,
		Pos,
		FVector2D::ZeroVector,
		0.f,
		true
	);
	const FPointerEvent TouchEventEnd(
		TouchEventBegan.GetUserIndex(),
		TouchEventBegan.GetPointerIndex(),
		Pos,
		Pos,
		1.f,
		false
	);
	SlateApp.ProcessTouchStartedEvent(GenWindow, TouchEventBegan);
	SlateApp.ProcessTouchEndedEvent(TouchEventEnd);
	bSuccess = true;
}
