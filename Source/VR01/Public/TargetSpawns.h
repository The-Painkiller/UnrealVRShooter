// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <ACControl.h>
#include "Components/ActorComponent.h"
#include "TargetSpawns.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR01_API UTargetSpawns : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTargetSpawns();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent * thisComp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherIndex, bool bFromHit, const FHitResult &hitInfo);

	UPROPERTY(VisibleAnywhere)
		UACControl *MainController;
};
