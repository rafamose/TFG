// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Engine/Engine.h"
#include "MySaveGame.h"

void UMyBlueprintFunctionLibrary::SaveGame(AActor * MyActor)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance->PlayerLocation = MyActor->GetActorLocation();

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("MySlot"), 0);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Juego Guardado."));
}

void UMyBlueprintFunctionLibrary::LoadGame(AActor * MyActor) {
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("MySlot", 0));

	MyActor->SetActorLocation(SaveGameInstance->PlayerLocation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Juego Cargado."));
}
