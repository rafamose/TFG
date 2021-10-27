// Fill out your copyright notice in the Description page of Project Settings.

#include "Watcher.h"
#include "Math/TransformNonVectorized.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UWatcher::UWatcher()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	restart = true;

}


// Called when the game starts
void UWatcher::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();

	MyActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}
void UWatcher::FadeOut()
{
	APlayerController * Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	class APlayerController * MyPC = Cast<APlayerController>(Controller);
	MyPC->ClientSetCameraFade(true, FColor::Black, FVector2D(1.0, 0.0), 10.0);
}

// Called every frame
void UWatcher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (WatcherTrigger->IsOverlappingActor(MyActor))
	{
		FadeOut();
		MyActor->SetActorLocation(ActorPosition);
		restart = false;
	}

}

