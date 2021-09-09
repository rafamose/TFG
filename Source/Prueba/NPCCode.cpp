// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCCode.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"

// Sets default values

ANPCCode::ANPCCode()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCCode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Pero funciona o no"));

	static const FString ContextString(TEXT("Dialogue Context")); //String shown automaticaly in log errors


	MyDialogue = NpcMyDataTable->FindRow<FNewNpcDialogue>(FName(TEXT("1")), ContextString, true); //get row from datatable (first argument is the row number)
	if (MyDialogue)
	{
		FString DialogueLine1 = MyDialogue->Dialogue; //get de dialogue text
		UE_LOG(LogTemp, Warning, TEXT("Dialogo es este: %s"), *MyDialogue->Dialogue); //print dialogue text in a log
	}


	
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



