// Fill out your copyright notice in the Description page of Project Settings.

#include "MySaveGame.h"
#include "Engine/Engine.h"
#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InputComponent = CreateDefaultSubobject<UInputComponent>("Input Component");

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	InputComponent->BindAction("Save", IE_Pressed, this, &AMyCharacter::SaveGame);
	InputComponent->BindAction("Load", IE_Pressed, this, &AMyCharacter::LoadGame);
	UE_LOG(LogTemp, Warning, TEXT("Esto se ha cargado correctamente"));
}

void AMyCharacter::SaveGame() {
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance->PlayerLocation = this->GetActorLocation();

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("MySlot"), 0);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Juego Guardado."));
}

void AMyCharacter::LoadGame() {
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("MySlot", 0));

	this->SetActorLocation(SaveGameInstance->PlayerLocation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Juego Cargado."));
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

