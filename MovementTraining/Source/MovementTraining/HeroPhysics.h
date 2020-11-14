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
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	// Move
	
	UPROPERTY()
	class UHeroMovementComponent* Movement;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	virtual UPawnMovementComponent* GetMovementComponent() const override;

	// Jump
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float JumpHeight;
	
	bool IsJumpInput;
	void InputJump();
	void Jump();

	bool IsGrounded;

	// Collisions
	
	UFUNCTION()
	void OnHit(AActor* Self, AActor* Other, FVector Normal, const FHitResult& Hit);
	/*
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    */
};

