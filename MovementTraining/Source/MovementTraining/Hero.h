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
	UPROPERTY(EditAnywhere)
	float Bounciness = 0.5f; 
	
	UPROPERTY(EditAnywhere)
	FFloatRange Bounds;
	
public:
	// Sets default values for this pawn's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

