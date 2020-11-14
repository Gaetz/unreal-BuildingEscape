// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPhysics.h"
#include "Components/SphereComponent.h"
#include "HeroMovementComponent.h"

#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

AHeroPhysics::AHeroPhysics() : AHeroBase()
{
    Movement = CreateDefaultSubobject<UHeroMovementComponent>(TEXT("Movement"));
    Movement->UpdatedComponent = RootComponent;
}

void AHeroPhysics::BeginPlay()
{
    Super::BeginPlay();
    Root->SetSimulatePhysics(true);
    Root->SetNotifyRigidBodyCollision(true);
    Movement->SetActorParameters(Acceleration, MaxSpeed, JumpHeight);
    OnActorHit.AddDynamic(this, &AHeroPhysics::OnHit);
}

void AHeroPhysics::Tick(float DeltaTime)
{    
    Super::Tick(DeltaTime);

    
    
/*
    if(IsJumpInput)
    {
        Jump();
        IsJumpInput = false;
    }


    */
    // Reset hit
    bGrounded = false;
}

void AHeroPhysics::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Vertical", this, &AHeroPhysics::OnMoveForward);
    PlayerInputComponent->BindAxis("Horizontal", this, &AHeroPhysics::OnMoveRight);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHeroPhysics::OnJump);
}

bool AHeroPhysics::IsGrounded() const
{
    return bGrounded;
}

USphereComponent* AHeroPhysics::GetRootComponent()
{
    return Root;
}

void AHeroPhysics::OnMoveForward(float AxisValue)
{
    if (Movement && (Movement->UpdatedComponent == RootComponent))
    {
        Movement->AddInputVector(GetActorForwardVector() * AxisValue);
    }
}

void AHeroPhysics::OnMoveRight(float AxisValue)
{
    if (Movement && (Movement->UpdatedComponent == RootComponent))
    {
        Movement->AddInputVector(GetActorRightVector() * AxisValue);
    }
}

UPawnMovementComponent* AHeroPhysics::GetMovementComponent() const
{
    return Movement;
}


void AHeroPhysics::OnJump()
{
    if (Movement && (Movement->UpdatedComponent == RootComponent))
    {
        Movement->SetIsJumpInput(true);
    }
}

void AHeroPhysics::OnHit(AActor* Self, AActor* Other, FVector Normal, const FHitResult& Hit)
{
    if(FVector::DotProduct(Normal, GetActorUpVector()) > 0.99)
    {
        bGrounded = true;
    }
}

/*
void AHeroPhysics::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    IsGrounded = true;
}

void AHeroPhysics::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    IsGrounded = false;
}
*/
