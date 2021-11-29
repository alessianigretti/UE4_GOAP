// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

FString UAction::GetName()
{
	return "None";
}

FState UAction::GetCondition()
{
	FState condition;

	return condition;
}

TArray<FState> UAction::GetEffects()
{
	TArray<FState> effects;

	return effects;
}