#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultySpec,
    "Nans.TimelineSystem.Core.TimeManager.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(DifficultySpec)
void DifficultySpec::Define()
{
    Describe("How to use TimeManager", [this]() {
        It("should get an unique ID", [this]() {
        });

    });
}
#endif    // WITH_DEV_AUTOMATION_TESTS