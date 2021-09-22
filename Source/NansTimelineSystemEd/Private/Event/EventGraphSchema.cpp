// Copyright Nans Pellicari, 2021

#include "EventGraphSchema.h"

#include "Kismet2/BlueprintEditorUtils.h"

UK2Node_VariableGet* UNEventGraphSchema::SpawnVariableGetNode(const FVector2D GraphPosition,
	class UEdGraph* ParentGraph, FName VariableName, UStruct* Source) const
{
	return Super::SpawnVariableGetNode(GraphPosition, ParentGraph, VariableName, Source);
}

UK2Node_VariableSet* UNEventGraphSchema::SpawnVariableSetNode(const FVector2D GraphPosition,
	class UEdGraph* ParentGraph, FName VariableName, UStruct* Source) const
{
	return Super::SpawnVariableSetNode(GraphPosition, ParentGraph, VariableName, Source);
}
