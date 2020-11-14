// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "HeroBase.h"
#include "GameFramework/Pawn.h"
#include "Hero.generated.h"

class USphereComponent;
class UNiagaraComponent;

UCLASS()
class MOVEMENTTRAINING_API AHero : public AHeroBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Movement")
	float AccelerationFactor = 100.0f; 
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float MaxSpeed = 4000.0f; 
	
	UPROPERTY(EditAnywhere)
	float Bounciness = 0.5f; 
	
	UPROPERTY(EditAnywhere)
	FFloatRange Bounds;

	FVector Velocity = FVector::ZeroVector;
	
public:
	// Sets default values for this pawn's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetHorizontalInput(const float AxisValue);
	virtual void SetVerticalInput(const float AxisValue);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};

inline void AHero::SetHorizontalInput(const float AxisValue)
{
	PlayerInput.X = AxisValue;
}

inline void AHero::SetVerticalInput(const float AxisValue)
{
	PlayerInput.Y = AxisValue;
}