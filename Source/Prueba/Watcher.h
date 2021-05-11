// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Watcher.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBA_API UWatcher : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWatcher();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void FadeOut();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* WatcherTrigger;

	AActor* MyActor;
	AActor* Owner;

	UPROPERTY(EditAnywhere)
	FVector ActorPosition;
};
