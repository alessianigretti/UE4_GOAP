// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "UObject/NoExportTypes.h"
#include "Builder.generated.h"

class UAction;

using namespace std;

USTRUCT()
struct FGoal
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;

	UPROPERTY()
	float Insistence;
};

/**
 * 
 */
UCLASS()
class GOALORIENTEDBEHAVIOR_API UBuilder : public UObject
{
	GENERATED_BODY()
	
public:
	void Build();
	UAction* ChooseAction();

private:
	vector<FGoal> goals;
	vector<UAction*> actions;
};
