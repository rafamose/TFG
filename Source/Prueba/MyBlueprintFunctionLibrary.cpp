// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MySaveGame.h"

void UMyBlueprintFunctionLibrary::SaveGame(AActor * MyActor)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance->PlayerLocation = MyActor->GetActorLocation();

	FString LevelName = MyActor->GetWorld()->GetMapName();
	LevelName.RemoveFromStart(MyActor->GetWorld()->StreamingLevelsPrefix);
	SaveGameInstance->LevelName = LevelName;

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("MySlot"), 0);
	FString cadenaLocation = SaveGameInstance->PlayerLocation.ToString();


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Autoguardado activado"));
}

FVector UMyBlueprintFunctionLibrary::LoadGame(AActor * MyActor) {
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("MySlot", 0));

	UGameplayStatics::OpenLevel(MyActor->GetWorld(), FName(*SaveGameInstance->LevelName));

	return SaveGameInstance->PlayerLocation;
}
