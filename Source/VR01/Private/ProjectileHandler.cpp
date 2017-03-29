// Fill out your copyright notice in the Description page of Project Settings.

#include "VR01.h"
#include "ProjectileHandler.h"


// Sets default values for this component's properties
UProjectileHandler::UProjectileHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UProjectileHandler::BeginPlay()
{
	Super::BeginPlay();

	SecondBorn = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	//MainController = PawnActor->GetDefaultObject()->FindComponentByClass<UACControl>();
	PawnActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PawnActor) {
		MainController = PawnActor->FindComponentByClass<UACControl>();
	}
	//AActor::FindComponentByClass<UACControl>()
	// ...
}


// Called every frame
void UProjectileHandler::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (UGameplayStatics::GetRealTimeSeconds(GetWorld()) - SecondBorn > SecondsToDie) {
		DestroyProjectile();
		PrimaryComponentTick.bCanEverTick = false;
	}
	// ...
}

void UProjectileHandler::DestroyProjectile()
{
	UE_LOG(LogTemp, Warning, TEXT("Projectile Destroyed!"));
	MainController->DestroyProjectilePointer(GetOwner());
}

