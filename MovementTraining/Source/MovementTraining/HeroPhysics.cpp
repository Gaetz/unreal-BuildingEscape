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
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Velocity: %s"), *Velocity.ToString()));

    FVector2D Input = PlayerInput;
    Input.Normalize();

    const FVector Acceleration = FVector(Input.X, Input.Y, 0.0f) * AccelerationFactor;
    Velocity += Acceleration * DeltaTime;
    Velocity = FVector(FMath::Clamp(Velocity.X, -MaxSpeed, MaxSpeed), FMath::Clamp(Velocity.Y, -MaxSpeed, MaxSpeed), 0.0f);
    Root->SetPhysicsLinearVelocity(Velocity, true);

    

    
}
