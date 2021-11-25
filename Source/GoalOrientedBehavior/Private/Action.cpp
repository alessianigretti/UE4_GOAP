// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

FString UAction::GetName()
{
	return "None";
}

float UAction::GetGoalChange(const FGoal& goal)
{
	UE_LOG(LogTemp, Warning, TEXT("Goal change Base"));

	return 0.0f;
}