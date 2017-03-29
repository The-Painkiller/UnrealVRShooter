// Fill out your copyright notice in the Description page of Project Settings.

#include "VR01.h"
#include "TargetSpawns.h"


// Sets default values for this component's properties
UTargetSpawns::UTargetSpawns()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTargetSpawns::BeginPlay()
{
	Super::BeginPlay();
	
	MainController = GetWorld()->GetFirstPlayerController()->GetPawn()->FindComponentByClass<UACControl>();

	UStaticMeshComponent *tempMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	if (tempMesh != NULL)
		GetOwner()->FindComponentByClass<UStaticMeshComponent>()->OnComponentBeginOverlap.AddDynamic(this, &UTargetSpawns::OnHit);
	else
		UE_LOG(LogTemp, Warning, TEXT("No Mesh Component found"));
	// ...
	
}


// Called every frame
void UTargetSpawns::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTargetSpawns::OnHit(UPrimitiveComponent * thisComp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherIndex, bool bFromHit, const FHitResult &hitInfo)
{
	MainController->Score++;

	//FString nm = otherActor->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Name: %s"),*nm);
}

