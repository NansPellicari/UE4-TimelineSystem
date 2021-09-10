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
#include "Engine/EngineTypes.h"
#include "Misc/AutomationTest.h"
#include "NansTimelineSystemUE4/Public/Manager/GameLifeTimelineManager.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "NansUE4TestsHelpers/Public/Helpers/TestWorld.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Serialization/BufferArchive.h"

// TODO make specs instead of these
// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameLifeTimelineManagerTest,
"Nans.TimelineSystem.UE4.GameLifeTimelineManager.Test.CanPauseAndPlay", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FGameLifeTimelineManagerTest::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UFakeObject* FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
	FakeObject->SetMyWorld(World);
	UNGameLifeTimelineManager* TimelineManager = FNTimelineManagerDecoratorFactory::CreateObject<
		UNGameLifeTimelineManager>(
		FakeObject,
		1.f,
		FName("TestTimeline"),
		EObjectFlags::RF_MarkAsRootSet
	);

	// Begin test
	{
		TimelineManager->Play();
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 1.f, 0.2f)
		);
		NTestWorld::Tick(World);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 2.f, 0.2f)
		);
		TimelineManager->Pause();
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager count should stick to 2 after timeline manager paused"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 2.f, 0.2f)
		);
		TimelineManager->Play();
		NTestWorld::Tick(World);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager has been called still 3"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 3.f, 0.2f)
		);
		UGameplayStatics::SetGamePaused(FakeObject, true);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager count should stick to 3 after game paused"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 3.f, 0.2f)
		);
	}
	// End test

	NTestWorld::Destroy(World);
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameLifeTimelineManagerSerializationSameObjTest,
"Nans.TimelineSystem.UE4.GameLifeTimelineManager.Test.CanSerializeWithTheSameObjectInstance", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FGameLifeTimelineManagerSerializationSameObjTest::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UFakeObject* FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
	FakeObject->SetMyWorld(World);
	UNGameLifeTimelineManager* TimelineManager = FNTimelineManagerDecoratorFactory::CreateObject<
		UNGameLifeTimelineManager>(
		FakeObject,
		1.f,
		FName("TestTimeline"),
		EObjectFlags::RF_MarkAsRootSet
	);
	TimelineManager->Play();

	// Begin test
	{
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 2.f, 0.2f)
		);
		FBufferArchive ToBinary;
		TimelineManager->Serialize(ToBinary);
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		TimelineManager->SetLabel(FName("ChangedLabel")); // try to change label to checks if rewrite with the archive
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline manager has been called 3"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 3.f, 0.2f)
		);
		TEST_EQ(
			TEST_TEXT_FN_DETAILS("Timeline manager label changed"),
			TimelineManager->GetLabel(),
			FName("ChangedLabel")
		);
		FMemoryReader FromBinary = FMemoryReader(ToBinary, true);
		FromBinary.Seek(0);
		TimelineManager->Serialize(FromBinary);
		TEST_EQ(
			TEST_TEXT_FN_DETAILS("Timeline manager label reload from archive"),
			TimelineManager->GetLabel(),
			FName("TestTimeline")
		);
		TEST_TRUE(
			TEST_TEXT_FN_DETAILS("Timeline should be the same as the last serialization"),
			FMath::IsNearlyEqual(TimelineManager->GetCurrentTime(), 2.f, 0.2f)
		);
	}
	// End test

	NTestWorld::Destroy(World);
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}

// @formatter:off
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameLifeTimelineManagerSerializationWithEventsTest,
"Nans.TimelineSystem.UE4.GameLifeTimelineManager.Test.CanLoadEventsFromDifferentWorld", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// @formatter:on
bool FGameLifeTimelineManagerSerializationWithEventsTest::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UFakeObject* FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
	FakeObject->SetMyWorld(World);
	UNGameLifeTimelineManager* TimelineManager = FNTimelineManagerDecoratorFactory::CreateObject<
		UNGameLifeTimelineManager>(
		FakeObject,
		1.f,
		FName("TestTimeline"),
		EObjectFlags::RF_MarkAsRootSet
	);
	TimelineManager->Play();

	// Begin test
	{
		TimelineManager->CreateAndAddNewEvent(NAME_None);
		TimelineManager->CreateAndAddNewEvent(NAME_None);
		TimelineManager->CreateAndAddNewEvent(NAME_None);
		TEST_EQ(
			TEST_TEXT_FN_DETAILS("There is 3 Events in collection"), TimelineManager->GetTimeline()->GetEvents().Num(),
			3
		);

		// Save in memory
		FBufferArchive ToBinary;
		TimelineManager->Serialize(ToBinary);

		GEngine->Exec(World, TEXT("Exit"));
		NTestWorld::Destroy(World);
		UWorld* NewWorld = NTestWorld::CreateAndPlay(EWorldType::Game, true, FName("ANewWorld"));

		UFakeObject* NewFakeObject = NewObject<UFakeObject>(
			NewWorld,
			FName("MyNewFakeObject"),
			EObjectFlags::RF_MarkAsRootSet
		);
		NewFakeObject->SetMyWorld(NewWorld);
		UNGameLifeTimelineManager* NewTimelineManager = FNTimelineManagerDecoratorFactory::CreateObject<
			UNGameLifeTimelineManager>(
			NewFakeObject,
			1.f,
			FName("DiffTimelineLabel"),
			EObjectFlags::RF_MarkAsRootSet
		);

		// Load from memory
		FMemoryReader FromBinary = FMemoryReader(ToBinary, true);
		FromBinary.Seek(0);
		NewTimelineManager->Serialize(FromBinary);
		TEST_LE(
			TEST_TEXT_FN_DETAILS("There is 3 Events in collection"),
			NewTimelineManager->GetTimeline()->GetEvents().Num(), 3
		);
	}
	// End test

	NTestWorld::Destroy(World);
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}
