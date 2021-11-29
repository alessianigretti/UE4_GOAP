// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Builder.generated.h"

class UAction;
class UWorldModel;

UENUM()
enum EStateType
{
	None,
	IsHungry,
	HasFood,
	HasWater,
	IsRested,
};

USTRUCT()
struct FState
{
	GENERATED_BODY()

	UPROPERTY()
	TEnumAsByte<EStateType> StateType;

	UPROPERTY()
	bool Value;
};

/**
 * 
 */
UCLASS()
class GOALORIENTEDBEHAVIOR_API UBuilder : public UObject
{
	GENERATED_BODY()
	
public:
	void Build();
	TArray<UAction*> PlanAction();

private:
	UAction* GetActionThatFulfillsGoal(FState goalState);
	bool DoesFulfillGoal(FState goalState, UAction* action);
	bool IsLegalAction(TArray<FState> currentStates, UAction* action);

	TArray<UAction*> actions;
	FState initialState;
	FState finalState;
};
