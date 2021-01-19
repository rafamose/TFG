// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "ReporteDePosicion.h"
#include "Math/TransformNonVectorized.h"
#include "Math/Vector.h"

// Sets default values for this component's properties
UReporteDePosicion::UReporteDePosicion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReporteDePosicion::BeginPlay()
{
	Super::BeginPlay();
	FString Nombre = GetOwner()->GetName();
	FString Posicion = GetOwner()->GetTransform().GetLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("Hola wenas soy %s y estoy en %s"), *Nombre, *Posicion);

	// ...
	
}


// Called every frame
void UReporteDePosicion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

