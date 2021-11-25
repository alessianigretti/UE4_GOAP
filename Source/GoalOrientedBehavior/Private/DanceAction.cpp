// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceAction.h"
#include "Builder.h"

FString UDanceAction::GetName()
{
	return "Dance";
}

float UDanceAction::GetGoalChange(const FGoal& goal)
{
	return 0.0f;
}