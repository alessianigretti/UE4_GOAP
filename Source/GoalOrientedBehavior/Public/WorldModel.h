// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Builder.h"
#include "UObject/NoExportTypes.h"
#include "WorldModel.generated.h"

class UAction;

/**
 * 
 */
UCLASS()
class GOALORIENTEDBEHAVIOR_API UWorldModel : public UObject
{
	GENERATED_BODY()
	
public:
	TArray<FState> WorldState;

	void ApplyAction(UAction* action);
	bool UpdateIfContained(FState effect);
	bool IsGoalFulfilled(FState goal);
};
