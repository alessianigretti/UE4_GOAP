// Copyright Epic Games, Inc. All Rights Reserved.

#include "GoalOrientedBehaviorGameMode.h"
#include "GoalOrientedBehaviorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGoalOrientedBehaviorGameMode::AGoalOrientedBehaviorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
