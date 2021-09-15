// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
