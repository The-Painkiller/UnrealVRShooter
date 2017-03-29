// Fill out your copyright notice in the Description page of Project Settings.

#include "VR01.h"
#include "ACControl.h"


// Sets default values for this component's properties
UACControl::UACControl()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UACControl::FireProjectile()
{
	FVector ProjectileLoc = GetOwner()->GetActorLocation() + ProjectileSpawnLocation;
	UE_LOG(LogTemp, Warning, TEXT("Fire Fire!: %s"), *(ProjectileLoc).ToString());

	AActor *ProjTemp = GetWorld()->SpawnActor<AActor>(ProjectileBPClass, ProjectileLoc, GetOwner()->GetActorRotation());
	Projectiles.Add(ProjTemp);
	
	UStaticMeshComponent *ProjMesh = ProjTemp->FindComponentByClass<UStaticMeshComponent>();
	if (ProjMesh) {
		FVector PlayerViewLoc;
		FRotator PlayerViewRot;
		myPawn->GetNetOwningPlayer()->GetPlayerController(GetWorld())->GetPlayerViewPoint(PlayerViewLoc, PlayerViewRot);
		//FVector ShootDirection = PlayerViewRot.Vector() * 20000.f;
		FVector ShootDirection = FVector(PlayerViewRot.Vector().X * 20000.f, PlayerViewRot.Vector().Y*20000, PlayerViewRot.Vector().Z * 20000.f);
		ProjMesh->AddImpulse(ShootDirection);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("No Force"));
}

void UACControl::DestroyProjectilePointer(AActor *ProjectileToDelete)
{
	int32 DestroyIndex = 0;

	if (Projectiles.Contains(ProjectileToDelete))
	{
		for (int32 i = 0; i < Projectiles.Num() ; i++)
		{
			if (Projectiles[i] == ProjectileToDelete)
			{
				DestroyIndex = i;
			}
		}
		Projectiles.RemoveAt(DestroyIndex);
		ProjectileToDelete->Destroy(false, true);
		UE_LOG(LogTemp, Warning, TEXT("Pointers Deleted"));
	}
}

// Called when the game starts
void UACControl::BeginPlay()
{
	Super::BeginPlay();

	myPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	myPawn->FindComponentByClass <USphereComponent>()->SetSimulatePhysics(true);

	mydetails.myPos = GetOwner()->GetActorLocation();
	mydetails.myName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Position of %s is %s"), *mydetails.myName, *mydetails.myPos.ToString());

	InputComponent = GetWorld()->GetFirstPlayerController()->InputComponent;
	InputComponent->BindAction("Fire", IE_Pressed, this, &UACControl::FireProjectile);
	// ...
	
}


// Called every frame
void UACControl::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	FVector PlayerViewLoc;
	FRotator PlayerViewRot;
	myPawn->GetNetOwningPlayer()->GetPlayerController(GetWorld())->GetPlayerViewPoint(PlayerViewLoc, PlayerViewRot);
	FVector ShootDirection = PlayerViewRot.Vector() * 200.f;
	//DrawDebugLine(GetWorld(), PlayerViewLoc, ShootDirection, FColor::Cyan, false, 0.f, 0, 10.f);
	// ...
}

