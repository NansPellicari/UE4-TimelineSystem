// Copyright Nans Pellicari, 2021

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
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"DeveloperSettings",
				"NansCoreHelpers",
				"NansUE4TestsHelpers",
				"NansTimelineSystemCore",
			});
	}
}
