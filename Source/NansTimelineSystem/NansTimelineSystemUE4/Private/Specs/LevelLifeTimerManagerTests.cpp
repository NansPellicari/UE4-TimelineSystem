#include "CoreMinimal.h"
#include "Engine/DebugCameraController.h"
#include "Engine/Engine.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "EngineGlobals.h"
#include "Manager/LevelLifeTimelineManager.h"
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
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLevelLifeTimelineManagerTest,
"Nans.TimelineSystem.UE4.LevelLifeTimelineManager.Test.CanPauseAndPlay", EAutomationTestFlags::EditorContext |
EAutomationTestFlags::EngineFilter)
// clang-format on
bool FLevelLifeTimelineManagerTest::RunTest(const FString& Parameters)
{
	const double StartTime = FPlatformTime::Seconds();
	UWorld* World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
	// RF_MarkAsRootSet to avoid deletion when GC passes
	UMockObject* MockObject = NewObject<UMockObject>(World, FName("MyMockObject"), EObjectFlags::RF_MarkAsRootSet);
	MockObject->SetMyWorld(World);
	UNLevelLifeTimelineManager* TimelineManager =
		UNTimelineManagerBase::CreateObject<UNLevelLifeTimelineManager>(MockObject, EObjectFlags::RF_MarkAsRootSet);
	NTestWorld::CreateAndOpenNewLevel(World);

	// Begin test
	{
		TimelineManager->Play();
		NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 1"), TimelineManager->Counter, 1.f);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called 2"), TimelineManager->Counter, 2.f);
		TimelineManager->Pause();
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager count should stick to 2 after timeline manager paused"),
			TimelineManager->Counter,
			2.f);
		TimelineManager->Play();
		NTestWorld::Tick(World);

		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been called still 3"), TimelineManager->Counter, 3.f);
		UGameplayStatics::SetGamePaused(MockObject, true);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		NTestWorld::Tick(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager count should stick to 3 after game paused"), TimelineManager->Counter, 3.f);
		NTestWorld::CreateAndOpenNewLevel(World);
		TEST_EQ(TEST_TEXT_FN_DETAILS("Timeline manager has been reset"), TimelineManager->Counter, 0.f);
	}
	// End test

	GEngine->Exec(World, TEXT("Exit"));
	NTestWorld::Destroy(World);
	UE_LOG(LogTemp, Display, TEXT("2- Test run on %f ms"), (FPlatformTime::Seconds() - StartTime) * 1000.f);
	return true;
}
