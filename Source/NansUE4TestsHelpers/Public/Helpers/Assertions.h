// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"
#include "Core\Public\Misc\AutomationTest.h"
#include "INansUE4TestsHelpers.h"

#if WITH_DEV_AUTOMATION_TESTS

#define TEST_TEXT_FN_DETAILS(Format, ...) \
	FString::Printf(TEXT("%s - %d: %s"), TEXT(__FILE__), __LINE__, *FString::Printf(TEXT(Format), ##__VA_ARGS__))
#define TEST_LOG(text, expression, expected) SpecHelpers::log(text, TEXT(#expression), #expected);

#define TEST_EQ(text, expression, expected)                       \
	if (SpecHelpers::TestEqual(text, expression, expected, this)) \
	{                                                             \
		TEST_LOG(text, expression, expected);                     \
	}

#define TEST_NE(text, expression, expected)                          \
	if (SpecHelpers::TestNotEqual(text, expression, expected, this)) \
	{                                                                \
		TEST_LOG(text, expression, expected);                        \
	}

#define TEST_GT(text, expression, expected)                             \
	if (SpecHelpers::TestGreaterThan(text, expression, expected, this)) \
	{                                                                   \
		TEST_LOG(text, expression, expected);                           \
	}

#define TEST_GE(text, expression, expected)                                    \
	if (SpecHelpers::TestGreaterOrEqualThan(text, expression, expected, this)) \
	{                                                                          \
		TEST_LOG(text, expression, expected);                                  \
	}

#define TEST_LT(text, expression, expected)                           \
	if (SpecHelpers::TestLowerThan(text, expression, expected, this)) \
	{                                                                 \
		TEST_LOG(text, expression, expected);                         \
	}
#define TEST_LE(text, expression, expected)                                  \
	if (SpecHelpers::TestLowerOrEqualThan(text, expression, expected, this)) \
	{                                                                        \
		TEST_LOG(text, expression, expected);                                \
	}

#define TEST_TRUE(text, expression)                    \
	if (SpecHelpers::TestTrue(text, expression, this)) \
	{                                                  \
		TEST_LOG(text, expression, TEXT("true"));      \
	}

#define TEST_FALSE(text, expression)                    \
	if (SpecHelpers::TestFalse(text, expression, this)) \
	{                                                   \
		TEST_LOG(text, expression, TEXT("false"));      \
	}

#define TEST_NOT_NULL(text, expression)                   \
	if (SpecHelpers::TestNotNull(text, expression, this)) \
	{                                                     \
		TEST_LOG(text, expression, TEXT("not nullptr"));  \
	}

#define TEST_NULL(text, expression)                     \
	if (SpecHelpers::TestNull(text, expression, this))  \
	{                                                   \
		TEST_LOG(text, expression, TEXT("is nullptr")); \
	}

#define TEST_THROW(expression, expectedType)                                                                                  \
	{                                                                                                                         \
		bool caught_expected = false;                                                                                         \
		try                                                                                                                   \
		{                                                                                                                     \
			expression;                                                                                                       \
		}                                                                                                                     \
		catch (expectedType)                                                                                                  \
		{                                                                                                                     \
			caught_expected = true;                                                                                           \
		}                                                                                                                     \
		catch (...)                                                                                                           \
		{                                                                                                                     \
			caught_expected = false;                                                                                          \
			UE_LOG(LogTemp,                                                                                                   \
				Display,                                                                                                      \
				TEXT("Wrong Exception type for " #expression " expression, should Trigger an error of type " #expectedType)); \
		}                                                                                                                     \
		FString Message = TEXT("Expression " #expression " should trigger an exception of type: " #expectedType);             \
		if (SpecHelpers::TestTrue(Message, caught_expected, this))                                                            \
		{                                                                                                                     \
			TEST_LOG(Message, expression, TEXT("true"));                                                                      \
		}                                                                                                                     \
	}

namespace SpecHelpers
{
	template <typename T1>
	bool TestTrue(const FString& Description, T1 Expression, FAutomationTestBase* This)
	{
		This->TestTrue(Description, Expression);
		return Expression == true;
	}

	template <typename T1>
	bool TestFalse(const FString& Description, T1 Expression, FAutomationTestBase* This)
	{
		This->TestFalse(Description, Expression);
		return Expression == false;
	}

	template <typename T1, typename T2>
	bool TestEqual(const FString& Description, T1 Expression, T2 Expected, FAutomationTestBase* This)
	{
		This->TestEqual(Description, Expression, Expected);
		return Expression == Expected;
	}

	template <typename T1, typename T2>
	bool TestNotEqual(const FString& Description, T1 Expression, T2 Expected, FAutomationTestBase* This)
	{
		This->TestNotEqual(Description, Expression, Expected);
		return Expression != Expected;
	}

	template <typename T, typename T2>
	bool TestGreaterThan(const FString& Description, T Expression, T2 Expected, FAutomationTestBase* This)
	{
		const bool IsGreaterThan = Expression > Expected;
		This->TestTrue(Description, IsGreaterThan);
		return IsGreaterThan;
	}

	template <typename T, typename T2>
	bool TestGreaterOrEqualThan(const FString& Description, T Expression, T2 Expected, FAutomationTestBase* This)
	{
		const bool IsGreaterThan = Expression >= Expected;
		This->TestTrue(Description, IsGreaterThan);
		return IsGreaterThan;
	}

	template <typename T, typename T2>
	bool TestLowerThan(const FString& Description, T Expression, T2 Expected, FAutomationTestBase* This)
	{
		const bool IsLowerThan = Expression < Expected;
		This->TestTrue(Description, IsLowerThan);
		return IsLowerThan;
	}

	template <typename T, typename T2>
	bool TestLowerOrEqualThan(const FString& Description, T Expression, T2 Expected, FAutomationTestBase* This)
	{
		const bool IsLowerThan = Expression <= Expected;
		This->TestTrue(Description, IsLowerThan);
		return IsLowerThan;
	}

	template <typename T>
	bool TestNull(const FString& Description, T Expression, FAutomationTestBase* This)
	{
		This->TestNull(Description, Expression);
		return Expression == nullptr;
	}

	template <typename T>
	bool TestNotNull(const FString& Description, T Expression, FAutomationTestBase* This)
	{
		This->TestNotNull(Description, Expression);
		return Expression != nullptr;
	}

	inline void log(const FString& Description, const FString& Expression, const FString& Expected)
	{
		UE_LOG(
			LogUE4TestsHelpers,
			Display,
			TEXT("Test succeed: \"%s\" with expression \"%s\" which expects \"%s\""),
			*Description,
			*Expression,
			*Expected
		);
	}

	inline bool WaitUntilTrue(const TFunction<bool()>& Pred, const TFunction<bool()>& TestResult, double TimeoutSeconds)
	{
		const double TimeoutEnd = FPlatformTime::Seconds() + TimeoutSeconds;
		while (!Pred() && FPlatformTime::Seconds() < TimeoutEnd)
		{
			FPlatformProcess::Sleep(0);
		}
		return TestResult();
	}
} // namespace SpecHelpers

#endif	  // WITH_DEV_AUTOMATION_TESTS
