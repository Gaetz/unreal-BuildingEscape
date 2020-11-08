// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Hero.generated.h"

class USphereComponent;
class UNiagaraComponent;

UCLASS()
class MOVEMENTTRAINING_API AHero : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereCollider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UNiagaraComponent* ParticleSystem;

	UPROPERTY(EditAnywhere)
	float AccelerationFactor = 100.0f; 

	UPROPERTY(EditAnywhere)
	float MaxSpeed = 4000.0f; 

	UPROPERTY(EditAnywhere)
	float Bounciness = 0.5f; 
	
	UPROPERTY(EditAnywhere)
	FFloatRange Bounds;
	
	FVector2D PlayerInput = FVector2D::ZeroVector;
	FVector Velocity = FVector::ZeroVector;
	
public:
	// Sets default values for this pawn's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void SetHorizontalInput(float AxisValue);
	void SetVerticalInput(float AxisValue);	

};

inline void AHero::SetHorizontalInput(float AxisValue)
{
	PlayerInput.X = AxisValue;
}

inline void AHero::SetVerticalInput(float AxisValue)
{
	PlayerInput.Y = AxisValue;
}
