// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectionBehaviour.h"
#include "Builder.h"

// Sets default values for this component's properties
USelectionBehaviour::USelectionBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USelectionBehaviour::BeginPlay()
{
	Super::BeginPlay();

	UBuilder* builder = NewObject<UBuilder>();
	builder->Build();
	builder->PlanAction();
}


// Called every frame
void USelectionBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

