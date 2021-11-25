// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "SleepAction.generated.h"

/**
 *
 */
UCLASS()
class GOALORIENTEDBEHAVIOR_API USleepAction : public UAction
{
	GENERATED_BODY()

protected:
	FString GetName() override;
	float GetGoalChange(const FGoal& goal) override;
};