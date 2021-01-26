// Fill out your copyright notice in the Description page of Project Settings.

#include "UObject/ConstructorHelpers.h"
#include "NPCCode.h"
#include "Engine/DataTable.h"

// Sets default values

ANPCCode::ANPCCode()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//search for a the Datatable with the Dialogues
	static ConstructorHelpers::FObjectFinder<UDataTable> NPCDialogue(TEXT("DataTable'/Game/ContenidoTFG/Dialogue5.Dialogue5'"));
	//if the datatable is found, it saves it in a class variable
	if (NPCDialogue.Succeeded()) {
		NPCmyDataTable = NPCDialogue.Object;
	}

	//Create a context from the row
	static const FString ContextString(TEXT("Dialogue Context"));

	//Get a row from the datatable
	FString* DialogueLine1 = NPCmyDataTable->FindRow<FString>(FName(TEXT("1")), ContextString, true);
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



