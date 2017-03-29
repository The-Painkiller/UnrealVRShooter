// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ACControl.generated.h"

struct MyDetails
{
	FVector myPos;
	FString myName;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR01_API UACControl : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACControl();
	MyDetails mydetails;

	UPROPERTY(EditAnywhere)
	AActor *myPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ProjectileSpawnLocation;

	void FireProjectile();

	void DestroyProjectilePointer(AActor *ProjectileToDelete);

	UPROPERTY(BlueprintReadWrite)
	int32 Score;

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	

private:
	UPROPERTY(VisibleAnywhere)
		FVector myPawnLocation;

	UInputComponent *InputComponent;

	//TArray <USphereComponent> *Projectiles;
	//USphereComponent *Projectile;
	UPROPERTY(VisibleAnywhere)
	TArray <AActor*> Projectiles;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileBPClass;
	
};
