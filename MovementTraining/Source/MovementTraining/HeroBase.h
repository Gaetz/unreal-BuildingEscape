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
	
	FVector2D PlayerInput = FVector2D::ZeroVector;
	
public:
	// Sets default values for this pawn's properties
	AHeroBase();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	static float MoveTowards(const float Current, const float Target, const float MaxDelta);
};
