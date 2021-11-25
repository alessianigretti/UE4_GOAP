// Fill out your copyright notice in the Description page of Project Settings.


#include "EatAction.h"
#include "Builder.h"

FString UEatAction::GetName()
{
	return "Eat";
}

float UEatAction::GetGoalChange(const FGoal& goal)
{
	if (goal.Name == "Eat")
	{
		return 1.0f;
	}
	else
	{
		return 0.0f;
	}
}