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

#include "PropertyEditorModule.h"
#include "TimelinePinFactory.h"

#define LOCTEXT_NAMESPACE "FNansTimelineSystemUE4Module"

void FNansTimelineSystemUE4Module::StartupModule()
{
	// create your factory and shared pointer to it.
	TSharedPtr<FTimelinePinFactory> Factory = MakeShareable(new FTimelinePinFactory());
	// and now register it.
	FEdGraphUtilities::RegisterVisualPinFactory(Factory);

	// =====================================================================================
	// TODO Search how to create custom field (config panel) from here
	// https://docs.unrealengine.com/en-US/Programming/Slate/DetailsCustomization/index.html
	// =====================================================================================
}

void FNansTimelineSystemUE4Module::ShutdownModule() {}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNansTimelineSystemUE4Module, NansTimelineSystemUE4)
