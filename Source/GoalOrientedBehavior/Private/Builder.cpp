// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder.h"
#include "Action.h"
#include "EatAction.h"
#include "BuyFoodAction.h"
#include "SleepAction.h"
#include "WorldModel.h"
#include "Algo/Reverse.h"

void UBuilder::Build()
{
	// Set up actions
	UEatAction* eatAction = NewObject<UEatAction>();
	UBuyFoodAction* buyFoodAction = NewObject<UBuyFoodAction>();
	USleepAction* sleepAction = NewObject<USleepAction>();

	actions.Add(eatAction);
	actions.Add(buyFoodAction);
	actions.Add(sleepAction);

	// Set up current state
	initialState.StateType = EStateType::IsHungry;
	initialState.Value = true;

	// Set up goal
	finalState.StateType = EStateType::IsHungry;
	finalState.Value = false;
}

TArray<UAction*> UBuilder::PlanAction()
{
	TArray<UAction*> plan;

	UWorldModel* worldModel = NewObject<UWorldModel>();
	worldModel->WorldState.Add(initialState);

	FState tempFinalState;
	tempFinalState.StateType = finalState.StateType;
	tempFinalState.Value = finalState.Value;

	while (!worldModel->IsGoalFulfilled(finalState))
	{
		UAction* action = GetActionThatFulfillsGoal(tempFinalState);
		if (action == nullptr)
		{
			break;
		}
		
		plan.Add(action);
		
		if (action->GetCondition().StateType == EStateType::None)
		{
			break;
		}

		tempFinalState.StateType = action->GetCondition().StateType;
		tempFinalState.Value = action->GetCondition().Value;

		if (initialState.StateType == tempFinalState.StateType &&
			initialState.Value == tempFinalState.Value)
		{
			break;
		}
	};

	Algo::Reverse(plan);

	for (UAction* action : plan)
	{
		FString name = action->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Chosen action %s"), *name);
	}

	return plan;
}

UAction* UBuilder::GetActionThatFulfillsGoal(FState goalState)
{
	for (UAction* action : actions)
	{
		if (DoesFulfillGoal(goalState, action))
		{
			return action;
		}
	}

	return NULL;
}

bool UBuilder::DoesFulfillGoal(FState goalState, UAction* action)
{
	for (FState effect : action->GetEffects())
	{
		if (effect.StateType == goalState.StateType &&
			effect.Value == goalState.Value)
		{
			return true;
		}
	}

	return false;
}

bool UBuilder::IsLegalAction(TArray<FState> currentStates, UAction* action)
{
	for (FState stateChecked : currentStates)
	{
		if (stateChecked.StateType == action->GetCondition().StateType &&
			stateChecked.Value == action->GetCondition().Value)
		{
			return true;
		}
	}

	return false;
}