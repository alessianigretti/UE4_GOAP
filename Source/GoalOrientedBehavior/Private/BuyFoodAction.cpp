// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyFoodAction.h"
#include "Builder.h"

FString UBuyFoodAction::GetName()
{
	return "Buy Food";
}

FState UBuyFoodAction::GetCondition()
{
	FState condition;

	condition.StateType = EStateType::None;

	return condition;
}

TArray<FState> UBuyFoodAction::GetEffects()
{
	TArray<FState> effects;

	FState hasFoodState;
	hasFoodState.StateType = EStateType::HasFood;
	hasFoodState.Value = true;

	effects.Add(hasFoodState);

	return effects;
}