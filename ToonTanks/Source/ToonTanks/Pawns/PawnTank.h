// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 100.0f;

	APlayerController* PLayerController;
	FVector MoveDirection;
	FQuat RotateDirection;
	bool bIsPlayerAlive;

	
	void ComputeMoveInput(float Value);
	void ComputeRotateInput(float Value);
	void Move();
	void Rotate();
	
public:
	APawnTank();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void HandleDestruction() override;
	bool GetIsPlayerAlive() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
