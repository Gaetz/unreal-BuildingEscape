// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Ball.generated.h"

UCLASS()
class PONG_API ABall final : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collider;

	void SetSpeed(float SpeedP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float Speed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
