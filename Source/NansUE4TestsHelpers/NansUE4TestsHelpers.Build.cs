// Copyright Nans Pellicari, 2021

namespace UnrealBuildTool.Rules
{
	public class NansUE4TestsHelpers : ModuleRules
	{
		public NansUE4TestsHelpers(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new[]
				{
					"Core"
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new[]
				{
					"CoreUObject",
					"Engine",
					"Slate",
					"SlateCore",
					"UMG",
					"InputCore"
				}
			);
		}
	}
}
