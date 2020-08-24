// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"

// Sets default values
APaddle::APaddle() : MaxSpeed(6000.0f), AccelerationFactor(50.0f), Acceleration(0), DecelerationFactor(0.92f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Velocity += FVector(0, 0, Acceleration);
	if(Velocity.Z > MaxSpeed) { Velocity.Z = MaxSpeed; }
	SetActorLocation(GetActorLocation() + Velocity * DeltaTime);
	Velocity *= DecelerationFactor;
}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &APaddle::MoveUpDown);
}

void APaddle::MoveUpDown(float Amount)
{
	Acceleration = AccelerationFactor * Amount;
}

