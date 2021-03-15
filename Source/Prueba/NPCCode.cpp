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
	
	static ConstructorHelpers::FObjectFinder<UDataTable> NPCDialogue(TEXT("DataTable'/Game/MisCosa/DialogoNpc1.DialogoNpc1'"));
	//if the datatable is found, it saves it in a class variable
	
	if (NPCDialogue.Succeeded()) {
		NpcMyDataTable = NPCDialogue.Object;
		UE_LOG(LogTemp, Warning, TEXT("Tengo la tabla, ahora que"));
	}

	//Create a context from the row


	//Get a row from the datatable


}

// Called when the game starts or when spawned
void ANPCCode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Pero funciona o no"));

	static const FString ContextString(TEXT("Dialogue Context"));

	//NPCmyDataTable->GetRowStruct();

	//TArray<FName> RowNames = NpcMyDataTable->GetRowNames();

	//for (int i = 0; i < RowNames.Num(); i++) {
		//UE_LOG(LogTemp, Warning, TEXT("Row: %s"), *RowNames[i].ToString());
	//}

	MyDialogue = NpcMyDataTable->FindRow<FNewNpcDialogue>(FName(TEXT("1")), ContextString, true);
	if (MyDialogue)
	{
		FString DialogueLine1 = MyDialogue->Dialogue;
		UE_LOG(LogTemp, Warning, TEXT("Dialogo es este: %s"), *MyDialogue->Dialogue);
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



