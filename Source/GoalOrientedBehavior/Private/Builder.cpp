// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder.h"
#include "Action.h"
#include "EatAction.h"
#include "SleepAction.h"
#include "DanceAction.h"

void UBuilder::Build()
{
	// Set up actions
	UEatAction* eatAction = NewObject<UEatAction>();
	USleepAction* sleepAction = NewObject<USleepAction>();
	UDanceAction* danceAction = NewObject<UDanceAction>();

	actions.push_back(eatAction);
	actions.push_back(sleepAction);
	actions.push_back(danceAction);

	// Set up goals
	FGoal eatGoal;
	eatGoal.Name = "Eat";
	eatGoal.Insistence = 5.0f;

	FGoal sleepGoal;
	sleepGoal.Name = "Sleep";
	sleepGoal.Insistence = 3.0f;

	goals.push_back(eatGoal);
	goals.push_back(sleepGoal);
}

UAction* UBuilder::ChooseAction()
{
	FGoal topGoal = goals[0];
	for (FGoal goal : goals)
	{
		if (goal.Insistence > topGoal.Insistence)
		{
			topGoal = goal;
		}
	}

	UAction* bestAction = actions[0];
	float bestUtility = -actions[0]->GetGoalChange(topGoal);
	for (UAction* action : actions)
	{
		float utility = action->GetGoalChange(topGoal);
		if (utility > bestUtility)
		{
			bestUtility = utility;
			bestAction = action;
		}
	}

	FString name = bestAction->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Chosen action %s"), *name);

	return bestAction;
}
