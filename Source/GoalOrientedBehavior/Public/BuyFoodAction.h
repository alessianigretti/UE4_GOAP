// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "BuyFoodAction.generated.h"

/**
 * 
 */
UCLASS()
class GOALORIENTEDBEHAVIOR_API UBuyFoodAction : public UAction
{
	GENERATED_BODY()

protected:
	FString GetName() override;
	FState GetCondition() override;
	TArray<FState> GetEffects() override;
};
