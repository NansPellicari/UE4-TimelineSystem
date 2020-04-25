// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;


/**
 * \defgroup Core A label
 */
public class NansTimelineSystemCore : ModuleRules
{
	public NansTimelineSystemCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
			}
			);


	}
}
