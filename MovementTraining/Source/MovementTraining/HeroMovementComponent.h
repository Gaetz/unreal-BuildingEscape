// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PawnMovementComponent.h"
#include "HeroMovementComponent.generated.h"

/**
 * Movement component for a HeroPhysics
 */
UCLASS()
class MOVEMENTTRAINING_API UHeroMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void SetActorParameters(float AccelerationP, float MaxSpeedP, float JumpHeightP, int NumberOfJumpsP,
							float AirAccelerationP);
	void SetIsJumpInput(bool bJumpInputP);
	
private:
	FVector Velocity = FVector::ZeroVector;
	bool bJumpInput = false;
	int JumpPhase = 0;
	
	UPROPERTY()
	float Acceleration;
	UPROPERTY()
	float MaxSpeed;
	UPROPERTY()
	float JumpHeight;
	UPROPERTY()
	int NumberOfJumps;
	UPROPERTY()
	float AirAcceleration;
	
	void Jump(class USphereComponent* Root);
};
