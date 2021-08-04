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

#include "Event/EventViewFactory.h"

#include "BlueprintEditorSettings.h"
#include "EventViewGraph.h"
#include "EventViewGraphSchema.h"
#include "Event/EventView.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Tools/BaseAssetToolkit.h"
#include "AssetTypeCategories.h"

#define LOCTEXT_NAMESPACE "EventViewFactory"

UNEventViewFactory::UNEventViewFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UNEventViewBlueprint::StaticClass();
	ParentClass = UNEventView::StaticClass();
}

UObject* UNEventViewFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	// Make sure we are trying to factory a EventView blueprint, then create and init one
	check(InClass->IsChildOf(UNEventViewBlueprint::StaticClass()));

	if (ParentClass == nullptr
		|| !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass)
		|| !ParentClass->IsChildOf(UNEventView::StaticClass()))
	{
		FFormatNamedArguments Args;
		Args.Add(
			TEXT("ClassName"),
			(ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)")
		);
		FMessageDialog::Open(
			EAppMsgType::Ok, FText::Format(
				LOCTEXT(
					"CannotCreateEventViewBlueprint",
					"Cannot create a Event View Blueprint based on the class '{ClassName}'."
				), Args
			)
		);
		return nullptr;
	}

	UNEventViewBlueprint* NewBP = CastChecked<UNEventViewBlueprint>(
		FKismetEditorUtilities::CreateBlueprint(
			ParentClass, InParent, InName, EBlueprintType::BPTYPE_Normal, UNEventViewBlueprint::StaticClass(),
			UBlueprintGeneratedClass::StaticClass(), NAME_None
		)
	);

	if (NewBP)
	{
		UNEventViewBlueprint* EventBP = UNEventViewBlueprint::FindRootEventViewBlueprint(NewBP);
		if (EventBP == nullptr)
		{
			// Only allow a EventView ability graph if there isn't one in a parent blueprint
			UEdGraph* NewGraph = FBlueprintEditorUtils::CreateNewGraph(
				NewBP, TEXT("Event View Graph"), UNEventViewGraph::StaticClass(),
				UNEventViewGraphSchema::StaticClass()
			);

#if WITH_EDITORONLY_DATA
			if (NewBP->UbergraphPages.Num())
			{
				FBlueprintEditorUtils::RemoveGraphs(NewBP, NewBP->UbergraphPages);
			}
#endif

			FBlueprintEditorUtils::AddUbergraphPage(NewBP, NewGraph);
			NewBP->LastEditedDocuments.Add(NewGraph);
			NewGraph->bAllowDeletion = false;

			UBlueprintEditorSettings* Settings = GetMutableDefault<UBlueprintEditorSettings>();
			if (Settings && Settings->bSpawnDefaultBlueprintNodes)
			{
				int32 NodePositionY = 0;
				FKismetEditorUtilities::AddDefaultEventNode(
					NewBP, NewGraph, FName(TEXT("OnBeforeAttached")), UNEventView::StaticClass(), NodePositionY
				);
				FKismetEditorUtilities::AddDefaultEventNode(
					NewBP, NewGraph, FName(TEXT("OnAfterAttached")), UNEventView::StaticClass(), NodePositionY
				);
				FKismetEditorUtilities::AddDefaultEventNode(
					NewBP, NewGraph, FName(TEXT("OnStart")), UNEventView::StaticClass(), NodePositionY
				);
				FKismetEditorUtilities::AddDefaultEventNode(
					NewBP, NewGraph, FName(TEXT("OnExpired")), UNEventView::StaticClass(), NodePositionY
				);
			}
		}
	}

	return NewBP;
}

bool UNEventViewFactory::ShouldShowInNewMenu() const
{
	return true;
}

uint32 UNEventViewFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Gameplay;
}
#undef LOCTEXT_NAMESPACE
