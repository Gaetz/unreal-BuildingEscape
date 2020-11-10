// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HeroBase.h"
#include "HeroPhysics.generated.h"

/**
 * 
 */
UCLASS()
class MOVEMENTTRAINING_API AHeroPhysics : public AHeroBase
{
	GENERATED_BODY()

public:
	AHeroPhysics();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
