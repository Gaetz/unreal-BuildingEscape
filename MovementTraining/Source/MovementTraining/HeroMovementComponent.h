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
	void SetActorParameters(float AccelerationP, float MaxSpeedP, float JumpHeightP);
	void SetIsJumpInput(bool bJumpInputP);
	
private:
	FVector Velocity = FVector::ZeroVector;
	bool bJumpInput = false;
	
	UPROPERTY()
	float Acceleration;
	UPROPERTY()
	float MaxSpeed;
	UPROPERTY()
	float JumpHeight;

	void Jump(class USphereComponent* Root);
};
