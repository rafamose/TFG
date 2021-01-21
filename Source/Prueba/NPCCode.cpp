// Fill out your copyright notice in the Description page of Project Settings.

#include "UObject/ConstructorHelpers.h"
#include "NPCCode.h"
#include "Engine/DataTable.h"

// Sets default values

ANPCCode::ANPCCode()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> NPCDialogue(TEXT("DataTable'/Game/ContenidoTFG/Dialogue5.Dialogue5'"));
	if (NPCDialogue.Succeeded()) {
		NPCmyDataTable = NPCDialogue.Object;
	}
}

// Called when the game starts or when spawned
void ANPCCode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCCode::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



