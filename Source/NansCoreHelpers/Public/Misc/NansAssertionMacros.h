// Copyright Nans Pellicari, 2021

#pragma once

#include "CoreMinimal.h"

#if !UE_BUILD_SHIPPING && WITH_DEV_AUTOMATION_TESTS && !(PLATFORM_ANDROID || PLATFORM_IOS)

extern NANSCOREHELPERS_API bool GNAssertThrowError;
extern NANSCOREHELPERS_API bool GIsGGTests;

#define mycheck(expr) AssertHelpers::CheckOrThrow(expr, TEXT(#expr))

#define mycheckf(expr, format, ...) AssertHelpers::CheckfOrThrow(!!(expr), TEXT(#expr), format, ##__VA_ARGS__)

#define myensureMsgf(InExpression, InFormat, ...) \
	(AssertHelpers::EnsureMsgfOrThrow(!!(InExpression), TEXT(#InExpression), InFormat, ##__VA_ARGS__))

namespace AssertHelpers
{
	template <typename ExprType>
	bool CheckOrThrow(const bool Result, const ExprType& Expr)
	{
		if (GIsAutomationTesting || GIsGGTests)
		{
			if (UNLIKELY(!(Result)))
			{
				throw Expr;
			}
		}
		else
		{
			checkf(Result, Expr);
		}

		return true;
	}

	template <typename ExprType, typename FmtType, typename... Types>
	bool LogAndThrow(const bool Result, const ExprType& Expr, const FmtType& Format, Types ... Args)
	{
		if (!Result)
		{
			UE_LOG(LogTemp, Display, Format, Args...);
			if (GNAssertThrowError) throw Expr;
		}
		return Result;
	}

	template <typename ExprType, typename FmtType, typename... Types>
	bool CheckfOrThrow(const bool Result, const ExprType& Expr, const FmtType& Format, Types ... Args)
	{
		if (GIsAutomationTesting || GIsGGTests)
		{
			return AssertHelpers::LogAndThrow(Result, Expr, Format, Args...);
		}
		checkf(Result, Format, Args...);
		return true;
	}

	template <typename ExprType, typename FmtType, typename... Types>
	bool EnsureMsgfOrThrow(const bool Result, const ExprType& Expr, const FmtType& Format, Types ... Args)
	{
		if (GIsAutomationTesting || GIsGGTests)
		{
			return AssertHelpers::LogAndThrow(Result, Expr, Format, Args...);
		}
		return ensureMsgf(Result, Format, Args...);
	}
} // namespace AssertHelpers
#else
#define mycheck(expr) check(expr)
#define mycheckf(expr, format, ...) checkf(expr, format, ##__VA_ARGS__)
#define myensureMsgf(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, ##__VA_ARGS__)
#endif
