// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Builder.h"
#include "UObject/NoExportTypes.h"
#include "Action.generated.h"

/**
 * 
 */
UCLASS()
class GOALORIENTEDBEHAVIOR_API UAction : public UObject
{
	GENERATED_BODY()
	
public:
	virtual FString GetName();
	virtual FState GetCondition();
	virtual TArray<FState> GetEffects();
};
