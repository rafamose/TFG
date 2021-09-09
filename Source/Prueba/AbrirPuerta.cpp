// Fill out your copyright notice in the Description page of Project Settings.

#include "AbrirPuerta.h"
#include "Math/TransformNonVectorized.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UAbrirPuerta::UAbrirPuerta()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbrirPuerta::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	actorRotation = Owner->GetActorRotation();
	// ...
	
}

void UAbrirPuerta::OpenDoor()
{
	

	Owner->SetActorRotation( actorRotation + FRotator(0.f, -90.f, 0.f));
}

void UAbrirPuerta::CloseDoor()
{
	Owner->SetActorRotation(actorRotation);
}


// Called every frame
void UAbrirPuerta::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();

	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}

	// ...
}

