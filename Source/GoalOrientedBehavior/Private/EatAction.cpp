// Fill out your copyright notice in the Description page of Project Settings.


#include "EatAction.h"
#include "Builder.h"

FString UEatAction::GetName()
{
	return "Eat";
}

FState UEatAction::GetCondition()
{
	FState hasFoodCondition;
	hasFoodCondition.StateType = EStateType::HasFood;
	hasFoodCondition.Value = true;

	return hasFoodCondition;
}

TArray<FState> UEatAction::GetEffects()
{
	TArray<FState> effects;

	FState isHungryState;
	isHungryState.StateType = EStateType::IsHungry;
	isHungryState.Value = false;

	FState hasFoodState;
	hasFoodState.StateType = EStateType::HasFood;
	hasFoodState.Value = false;

	effects.Add(isHungryState);
	effects.Add(hasFoodState);

	return effects;
}