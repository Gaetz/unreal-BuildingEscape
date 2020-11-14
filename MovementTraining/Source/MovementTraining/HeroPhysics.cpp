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
    OnActorHit.AddDynamic(this, &AHeroPhysics::OnHit);
}

void AHeroPhysics::Tick(float DeltaTime)
{    
    Super::Tick(DeltaTime);


    if(IsJumpInput)
    {
        Jump();
        IsJumpInput = false;
    }

    // Reset hit
    IsGrounded = false;
}

void AHeroPhysics::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Vertical", this, &AHeroPhysics::MoveForward);
    PlayerInputComponent->BindAxis("Horizontal", this, &AHeroPhysics::MoveRight);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHeroPhysics::InputJump);
}

void AHeroPhysics::MoveForward(float AxisValue)
{
    if (Movement && (Movement->UpdatedComponent == RootComponent))
    {
        Movement->AddInputVector(GetActorForwardVector() * AxisValue);
    }
}

void AHeroPhysics::MoveRight(float AxisValue)
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

void AHeroPhysics::InputJump()
{
    IsJumpInput = true;
}

void AHeroPhysics::Jump()
{
    if(IsGrounded)
    {
        const float Impulse = FMath::Sqrt(-2.0f * GetWorld()->GetGravityZ() * JumpHeight);
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Impulse: %f"), Impulse));
        Root->AddImpulse(FVector::UpVector * Impulse * Root->GetBodyInstance()->GetBodyMass());
    }
}

void AHeroPhysics::OnHit(AActor* Self, AActor* Other, FVector Normal, const FHitResult& Hit)
{
    IsGrounded = true;
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
