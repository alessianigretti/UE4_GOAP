// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldModel.h"
#include "Action.h"

void UWorldModel::ApplyAction(UAction* action)
{
	for (FState effect : action->GetEffects())
	{
		if (!UpdateIfContained(effect))
		{
			WorldState.Add(effect);
		}
	}
}

bool UWorldModel::UpdateIfContained(FState effect)
{
	for (FState existingState : WorldState)
	{
		if (existingState.StateType == effect.StateType)
		{
			existingState.Value = effect.Value;
			return true;
		}
	}

	return false;
}

bool UWorldModel::IsGoalFulfilled(FState goal)
{
	for (FState existingState : WorldState)
	{
		if (existingState.StateType == goal.StateType &&
			existingState.Value == goal.Value)
		{
			return true;
		}
	}

	return false;
}