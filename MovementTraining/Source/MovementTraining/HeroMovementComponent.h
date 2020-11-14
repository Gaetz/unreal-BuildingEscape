// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "HeroMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class MOVEMENTTRAINING_API UHeroMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;



private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Movement, meta = (AllowPrivateAccess = "true"))
	float Acceleration = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Movement, meta = (AllowPrivateAccess = "true"))
	float MaxSpeed = 2000;
	
	FVector Velocity = FVector::ZeroVector;
	
};
