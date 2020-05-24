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

#include "NansTimelineSystemUE4.h"

#include "TimelinePinFactory.h"

#define LOCTEXT_NAMESPACE "FNansTimelineSystemUE4Module"

void FNansTimelineSystemUE4Module::StartupModule()
{
	// create your factory and shared pointer to it.
	TSharedPtr<FTimelinePinFactory> Factory = MakeShareable(new FTimelinePinFactory());
	// and now register it.
	FEdGraphUtilities::RegisterVisualPinFactory(Factory);
}

void FNansTimelineSystemUE4Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNansTimelineSystemUE4Module, NansTimelineSystemUE4)