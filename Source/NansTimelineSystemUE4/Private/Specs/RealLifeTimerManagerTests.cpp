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
#include "Manager/RealLifeTimelineManager.h"
#include "Misc/AutomationTest.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "NansUE4TestsHelpers/Public/Helpers/TestWorld.h"
#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/Tests/AutomationCommon.h"
#include "TimerManager.h"

/**
 * For an unknown reason, I can't create a Spec with World ticking,
 * frame doesn't increase. But a SIMPLE_AUTOMATION_TEST works... o.O
 */
// clang-format off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRealLifeTimelineManagerTest,
"Nans.TimelineSystem.UE4.RealLifeTimelineManager.Test.CanPauseAndPlayButShouldNotBeAffectedByGamePause", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// clang-format on
bool FRealLifeTimelineManagerTest::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UMockObject* MockObject = NewObject<UMockObject>(World, FName("MyMockObject"), EObjectFlags::RF_MarkAsRootSet);
	MockObject->SetMyWorld(World);
	UNRealLifeTimelineManager* TimelineManager = UNTimelineManagerBaseAdapter::CreateObject<UNRealLifeTimelineManager>(
		MockObject, FName("TestTimeline"), EObjectFlags::RF_MarkAsRootSet);

	// Begin test
	{
		TimelineManager->Play();
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->GetTimelineTime(), 1.f);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"), TimelineManager->GetTimelineTime(), 2.f);
		TimelineManager->Pause();
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager should never be paused means continue increment"),
			TimelineManager->GetTimelineTime(),
			6.f);
		TimelineManager->Play();
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 7"), TimelineManager->GetTimelineTime(), 7.f);
		UGameplayStatics::SetGamePaused(MockObject, true);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 10"), TimelineManager->GetTimelineTime(), 10.f);
	}
	// End test

	NTestWorld::Destroy(World);
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// clang-format off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRealLifeTimelineManagerSerializationTest,
"Nans.TimelineSystem.UE4.RealLifeTimelineManager.Test.CanSerialize", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// clang-format on
bool FRealLifeTimelineManagerSerializationTest::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UMockObject* MockObject = NewObject<UMockObject>(World, FName("MyMockObject"), EObjectFlags::RF_MarkAsRootSet);
	MockObject->SetMyWorld(World);
	UNRealLifeTimelineManager* TimelineManager = UNTimelineManagerBaseAdapter::CreateObject<UNRealLifeTimelineManager>(
		MockObject, FName("TestTimeline"), EObjectFlags::RF_MarkAsRootSet);

	// Begin test
	{
	}
	// End test

	NTestWorld::Destroy(World);
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}
