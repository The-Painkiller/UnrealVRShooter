// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <ACControl.h>
#include "Components/ActorComponent.h"
#include "ProjectileHandler.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR01_API UProjectileHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProjectileHandler();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void DestroyProjectile();

	UPROPERTY(VisibleAnywhere)
		UACControl *MainController;

	UPROPERTY(VisibleAnywhere)
	AActor *PawnActor;

	UPROPERTY(EditAnywhere)
		float SecondsToDie = 5.f;

private:
	float SecondBorn;
};
