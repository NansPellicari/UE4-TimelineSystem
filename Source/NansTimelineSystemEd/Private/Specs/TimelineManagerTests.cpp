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

#include "CoreMinimal.h"
#include "Engine/DebugCameraController.h"
#include "Engine/Engine.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "EngineGlobals.h"
#include "Misc/AutomationTest.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "NansUE4TestsHelpers/Public/Helpers/TestWorld.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Specs/TimelineManagerFake.h"
#include "Specs/TimelineManagerTickableOnPauseFake.h"
#include "TimerManager.h"

// TODO make specs instead of these
// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTimelineTestCounterIncrease,
"Nans.TimelineSystem.UE4.TimelineManager.Test.ShouldTickThanksToWorldTimerManager", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FTimelineTestCounterIncrease::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game);
	FTimerManager& TimerManager = World->GetTimerManager();
	FNTimelineManagerFake* TimelineManager = new FNTimelineManagerFake();
	TimerManager.SetTimer(TimelineManager->TimerHandle, TimelineManager->TimerDelegate, TimelineManager->GetTimeline()->GetTickInterval(), true);

	// Begin test
	{
		TimelineManager->Play();
		// @formatter:off
		TEST_TRUE(TEST_TEXT_FN_DETAILS("Handle should be valid after calling SetTimer"), TimelineManager->TimerHandle.IsValid());
		TEST_TRUE(TEST_TEXT_FN_DETAILS("TimerExists called with a pending timer"), TimerManager.TimerExists(TimelineManager->TimerHandle));
		TEST_TRUE(TEST_TEXT_FN_DETAILS("IsTimerActive called with a pending timer"), TimerManager.IsTimerActive(TimelineManager->TimerHandle));
		TEST_FALSE(TEST_TEXT_FN_DETAILS("IsTimerPaused called with a pending timer"), TimerManager.IsTimerPaused(TimelineManager->TimerHandle));
		TEST_TRUE(TEST_TEXT_FN_DETAILS("GetTimerRate called with a pending timer"), (TimerManager.GetTimerRate(TimelineManager->TimerHandle) == TimelineManager->GetTimeline()->GetTickInterval()));
		TEST_TRUE(TEST_TEXT_FN_DETAILS("GetTimerElapsed called with a pending timer"), (TimerManager.GetTimerElapsed(TimelineManager->TimerHandle) == 0.f));
		TEST_TRUE(TEST_TEXT_FN_DETAILS("GetTimerRemaining called with a pending timer"), (TimerManager.GetTimerRemaining(TimelineManager->TimerHandle) == TimelineManager->GetTimeline()->GetTickInterval()));
		// @formatter:on

		// small tick to move the timer from the pending list to the active list, the timer will start counting time after this tick
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->Counter, 1.f);
	}
	// End test

	TimerManager.ClearTimer(TimelineManager->TimerHandle);
	NTestWorld::Destroy(World);
	TimelineManager = nullptr;
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTimelineTestPauseAndPlay, "Nans.TimelineSystem.UE4.TimelineManager.Test.ShouldPauseAndPlay",
EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FTimelineTestPauseAndPlay::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game);
	FTimerManager& TimerManager = World->GetTimerManager();
	FNTimelineManagerFake* TimelineManager = new FNTimelineManagerFake();
	TimerManager.SetTimer(TimelineManager->TimerHandle, TimelineManager->TimerDelegate, TimelineManager->GetTimeline()->GetTickInterval(), true);

	// Begin test
	{
		TimelineManager->Play();
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has not been called"), TimelineManager->Counter, 0.f);
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->Counter, 1.f);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"), TimelineManager->Counter, 2.f);
		TimelineManager->Pause();
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 2"), TimelineManager->Counter, 2.f);
		TimelineManager->Play();
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 3"), TimelineManager->Counter, 3.f);
	}
	// End test

	TimerManager.ClearTimer(TimelineManager->TimerHandle);
	NTestWorld::Destroy(World);
	TimelineManager = nullptr;
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTimelineTestTimerManagerPauseAndPlay,
"Nans.TimelineSystem.UE4.TimelineManager.Test.ShouldPauseAndPlayCauseOfTimerManager", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FTimelineTestTimerManagerPauseAndPlay::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game);
	FTimerManager& TimerManager = World->GetTimerManager();
	FNTimelineManagerFake* TimelineManager = new FNTimelineManagerFake();
	TimerManager.SetTimer(TimelineManager->TimerHandle, TimelineManager->TimerDelegate, TimelineManager->GetTimeline()->GetTickInterval(), true);

	// Begin test
	{
		TimelineManager->Play();
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has not been called"), TimelineManager->Counter, 0.f);
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->Counter, 1.f);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"), TimelineManager->Counter, 2.f);
		TimerManager.PauseTimer(TimelineManager->TimerHandle);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 2"), TimelineManager->Counter, 2.f);
		TimerManager.UnPauseTimer(TimelineManager->TimerHandle);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 3"), TimelineManager->Counter, 3.f);
	}
	// End test

	TimerManager.ClearTimer(TimelineManager->TimerHandle);
	NTestWorld::Destroy(World);
	TimelineManager = nullptr;
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTimelineTestTimerManagerGamePause,
"Nans.TimelineSystem.UE4.TimelineManager.Test.SetGamePauseShouldNotInfluenceTimerManagerAttachedToWorld",
EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FTimelineTestTimerManagerGamePause::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	UGameInstance* GI = World->GetGameInstance();
	FNTimelineManagerTickableOnPauseFake* TimelineManager = new FNTimelineManagerTickableOnPauseFake(World);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UFakeObject* FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
	FakeObject->SetMyWorld(World);

	// Begin test
	{
		TimelineManager->Play();
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has not been called"), TimelineManager->Counter, 0.f);
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->Counter, 1.f);
		UGameplayStatics::SetGamePaused(FakeObject, true);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"), TimelineManager->Counter, 2.f);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 3"), TimelineManager->Counter, 3.f);
		UGameplayStatics::SetGamePaused(FakeObject, false);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 4"), TimelineManager->Counter, 4.f);
		TimelineManager->Pause();
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 4"), TimelineManager->Counter, 4.f);
	}
	// End test

	NTestWorld::Destroy(World);
	FakeObject->ClearFlags(EObjectFlags::RF_Transient);
	FakeObject->RemoveFromRoot();
	TimelineManager = nullptr;
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTimelineTestTimerManagerGamePauseWithController,
"Nans.TimelineSystem.UE4.TimelineManager.Test.SetGamePauseInfluenceTimerManagerAttachedToWorldSTimerManager",
EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FTimelineTestTimerManagerGamePauseWithController::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	FTimerManager& TimerManager = World->GetTimerManager();

	// RF_MarkAsRootSet to avoid deletion when GC passes
	UFakeObject* FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
	FakeObject->SetMyWorld(World);
	APlayerController* PC = World->GetFirstPlayerController();

	if (PC == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No controller has been founded"));
		return false;
	}

	FNTimelineManagerFake* TimelineManager = new FNTimelineManagerFake();
	TimerManager.SetTimer(TimelineManager->TimerHandle, TimelineManager->TimerDelegate, TimelineManager->GetTimeline()->GetTickInterval(), true);
	CollectGarbage(EObjectFlags::RF_NoFlags);
	// Begin test
	{
		TimelineManager->Play();
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has not been called"), TimelineManager->Counter, 0.f);
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->Counter, 1.f);
		UGameplayStatics::SetGamePaused(FakeObject, true);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager Should stick to 1 count after making game paused"),
			TimelineManager->Counter,
			1.f);
		UGameplayStatics::SetGamePaused(FakeObject, false);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager tick once more after stopping game paused"), TimelineManager->Counter, 2.f);
	}
	// End test

	TimerManager.ClearTimer(TimelineManager->TimerHandle);
	FakeObject->ClearFlags(EObjectFlags::RF_Transient);
	FakeObject->RemoveFromRoot();
	NTestWorld::Destroy(World);
	TimelineManager = nullptr;
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}
