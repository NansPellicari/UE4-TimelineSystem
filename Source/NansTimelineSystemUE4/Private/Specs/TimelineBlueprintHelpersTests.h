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
#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformProcess.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/Tests/AutomationCommon.h"
#include "Serialization/BufferArchive.h"
#include "TimelineFactory.h"
#include "TimerManager.h"

// TODO make specs for these
// clang-format off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTimelineFactoryTest,
"Nans.TimelineSystem.UE4.TimelineFactory.Test.CanCreateNewTimeline", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// clang-format on
bool FTimelineFactoryTest::RunTest(const FString& Parameters)
{
	// const double StartTime = FPlatformTime::Seconds();
	// UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// // RF_MarkAsRootSet to avoid deletion when GC passes
	// UFakeObject* FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
	// FakeObject->SetMyWorld(World);

	// // Begin test
	// {
	// 	UNTimelineManagerDecorator* TimelineManager = UNTimelineBlueprintHelpers::CreateNewTimeline(
	// 		FakeObject, UNRealLifeTimelineManager::StaticClass(), 1.f, FName("TempTimeline"));
	// 	TEST_NOT_NULL(TEST_TEXT_FN_DETAILS("Should not be null"), TimelineManager);
	// 	UNRealLifeTimelineManager* RealTimelineManager = Cast<UNRealLifeTimelineManager>(TimelineManager);
	// 	TEST_NOT_NULL(TEST_TEXT_FN_DETAILS("Should not be null"), RealTimelineManager);
	// }
	// // End test

	// NTestWorld::Destroy(World);
	// UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	// return true;
}
