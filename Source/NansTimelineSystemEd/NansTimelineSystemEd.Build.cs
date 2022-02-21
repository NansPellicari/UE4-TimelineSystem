// Copyright Nans Pellicari, 2021

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class NansTimelineSystemEd : ModuleRules
	{
		public NansTimelineSystemEd(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"UnrealEd",
					"BlueprintGraph",
					"GraphEditor",
					"Slate",
					"SlateCore",
					"InputCore",
					"EditorStyle",
					"Kismet",
					"KismetCompiler",
					"EditorWidgets",
					"PropertyEditor",
					"DetailCustomizations",
					"AssetTools",
					"Projects",
					"NansCoreHelpers",
					"NansUE4TestsHelpers",
					"NansTimelineSystemCore",
					"NansTimelineSystemUE4"
				});

			PublicIncludePaths.AddRange(
				new string[]
				{
					ModuleDirectory + "/Public"
				});

			// Thanks to https://answers.unrealengine.com/questions/258689/how-to-include-private-header-files-of-other-modul.html
			string EnginePath = Path.GetFullPath(Target.RelativeEnginePath);

			PrivateIncludePaths.AddRange(
				new string[]
				{
					Path.Combine(EnginePath, "Source/Developer/LogVisualizer/Private"),
					ModuleDirectory + "/Private"
				});
		}
	}
}
