// Fill out your copyright notice in the Description page of Project Settings.


#include "SleepAction.h"
#include "Builder.h"

FString USleepAction::GetName()
{
	return "Sleep";
}

FState USleepAction::GetCondition()
{
	FState condition;

	condition.StateType = EStateType::None;

	return condition;
}

TArray<FState> USleepAction::GetEffects()
{
	TArray<FState> effects;

	FState isRestedState;
	isRestedState.StateType = EStateType::IsRested;
	isRestedState.Value = true;

	effects.Add(isRestedState);

	return effects;
}