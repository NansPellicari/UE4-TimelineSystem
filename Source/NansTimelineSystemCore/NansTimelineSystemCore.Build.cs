// Copyright Nans Pellicari, 2021

using UnrealBuildTool;

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