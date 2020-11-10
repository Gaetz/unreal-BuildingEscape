// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HeroBase.generated.h"

class USphereComponent;
class UNiagaraComponent;

UCLASS()
class MOVEMENTTRAINING_API AHeroBase : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	USphereComponent* Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UNiagaraComponent* ParticleSystem;

	UPROPERTY(EditAnywhere)
	float AccelerationFactor = 100.0f; 
	
	UPROPERTY(EditAnywhere)
	float MaxSpeed = 4000.0f; 
	
	FVector2D PlayerInput = FVector2D::ZeroVector;
	FVector Velocity = FVector::ZeroVector;
	
public:
	// Sets default values for this pawn's properties
	AHeroBase();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	virtual void SetHorizontalInput(const float AxisValue);
	virtual void SetVerticalInput(const float AxisValue);
};

inline void AHeroBase::SetHorizontalInput(const float AxisValue)
{
	PlayerInput.X = AxisValue;
}

inline void AHeroBase::SetVerticalInput(const float AxisValue)
{
	PlayerInput.Y = AxisValue;
}