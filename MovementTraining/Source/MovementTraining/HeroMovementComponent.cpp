// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroMovementComponent.h"
#include "HeroBase.h"
#include "HeroPhysics.h"
#include "Components/SphereComponent.h"

void UHeroMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Make sure that everything is still valid, and that we are allowed to move.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }
    AHeroPhysics* Owner = Cast<AHeroPhysics>(PawnOwner);

    
    // Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
    const FVector DesiredMovement = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * MaxSpeed;
    const float RealAcceleration = Owner->IsGrounded() ? Acceleration : AirAcceleration;
    Velocity.X = AHeroBase::MoveTowards(Velocity.X, DesiredMovement.X, RealAcceleration * DeltaTime);
    Velocity.Y = AHeroBase::MoveTowards(Velocity.Y, DesiredMovement.Y, RealAcceleration * DeltaTime);

    if (!Velocity.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(Velocity, UpdatedComponent->GetComponentRotation(), true, Hit);

        // If we bumped into something, try to slide along it
        if (Hit.IsValidBlockingHit())
        {
            SlideAlongSurface(Velocity, 1.f - Hit.Time, Hit.Normal, Hit);
        }
    }

    // Jump
    if(Owner->IsGrounded())
    {
        JumpPhase = 0;
    }
    
    if (bJumpInput && (Owner->IsGrounded() || JumpPhase < NumberOfJumps))
    {
        ++JumpPhase;
        Jump(Owner->GetRootComponent());
    }
    bJumpInput = false;
}

void UHeroMovementComponent::SetActorParameters(float AccelerationP, float MaxSpeedP, float JumpHeightP, int NumberOfJumpsP,
                                                float AirAccelerationP)
{
    Acceleration = AccelerationP;
    MaxSpeed = MaxSpeedP;
    JumpHeight = JumpHeightP;
    NumberOfJumps = NumberOfJumpsP;
    AirAcceleration = AirAccelerationP;
}

void UHeroMovementComponent::SetIsJumpInput(bool bJumpInputP)
{
    bJumpInput = bJumpInputP;
}

void UHeroMovementComponent::Jump(USphereComponent* Root)
{
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Impulse: %f"), Impulse));
    (Cast<AHeroPhysics>(PawnOwner))->SetGrounded(false);
    float Impulse = FMath::Sqrt(-2.0f * GetWorld()->GetGravityZ() * JumpHeight);
    // Take into account previous jump
    FVector LinearVelocity = Root->GetPhysicsLinearVelocity();
    if(LinearVelocity.Z > 0)
    {
        Impulse = FMath::Max( Impulse - LinearVelocity.Z, 0.0f);
    }
    // Add jump impulse
    Root->AddImpulse(FVector::UpVector * Impulse * Root->GetBodyInstance()->GetBodyMass());

    // Limit jump speed
    LinearVelocity = Root->GetPhysicsLinearVelocity();
    if(LinearVelocity.Z > Impulse)
    {
        LinearVelocity.Z = Impulse;
    }
    Root->SetPhysicsLinearVelocity(LinearVelocity);
}
