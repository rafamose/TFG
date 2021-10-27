// Fill out your copyright notice in the Description page of Project Settings.

#include "MySaveGame.h"
#include "PRUEBA.h"

UMySaveGame::UMySaveGame()
{
	PlayerLocation = FVector(0.f, 0.f, 0.f);
	SaveSlotName = TEXT("TestSaveSlot");
	UserIndex = 0;
	LevelName = TEXT("Level1");
}
