// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;


public class NansTimelineSystemUE4 : ModuleRules
{
	public NansTimelineSystemUE4(ReadOnlyTargetRules Target) : base(Target)
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
				"Engine",
				"Slate",
				"SlateCore",
				"NansTimelineSystemCore",
				"NansUE4TestsHelpers"
			}
			);
	}
}
