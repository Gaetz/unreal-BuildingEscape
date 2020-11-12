// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPhysics.h"
#include "Components/SphereComponent.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

AHeroPhysics::AHeroPhysics() : AHeroBase()
{
    
}

void AHeroPhysics::BeginPlay()
{
    Super::BeginPlay();
}

void AHeroPhysics::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Input = FVector(PlayerInput.X, PlayerInput.Y, 0);
    Input = Input.GetClampedToMaxSize(1.0f);
    const FVector DesiredVelocity = Input * MaxSpeed;

    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("DesiredVelocity: %s"), *DesiredVelocity.ToString()));

    
    const float Acceleration = AccelerationFactor * DeltaTime;
    Velocity.X = MoveTowards(Velocity.X, DesiredVelocity.X, Acceleration);
    Velocity.Y = MoveTowards(Velocity.Y, DesiredVelocity.Y, Acceleration);

    Root->SetPhysicsLinearVelocity(Velocity, true);

    // Clamp physical velocity
    FVector PhysVelocity = Root->GetPhysicsLinearVelocity();
    PhysVelocity.X = FMath::Clamp(PhysVelocity.X, -MaxSpeed, MaxSpeed);
    PhysVelocity.Y = FMath::Clamp(PhysVelocity.Y, -MaxSpeed, MaxSpeed);
    Root->SetPhysicsLinearVelocity(PhysVelocity);
}

void AHeroPhysics::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    
}
