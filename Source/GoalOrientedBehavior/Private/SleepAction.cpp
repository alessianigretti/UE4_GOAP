// Fill out your copyright notice in the Description page of Project Settings.


#include "SleepAction.h"
#include "Builder.h"

FString USleepAction::GetName()
{
	return "Sleep";
}

float USleepAction::GetGoalChange(const FGoal& goal)
{
	if (goal.Name == "Sleep")
	{
		return 1.0f;
	}
	else
	{
		return 0.0f;
	}
}