// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroMovementComponent.h"
#include "HeroBase.h"

void UHeroMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Make sure that everything is still valid, and that we are allowed to move.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    // Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
    const FVector DesiredMovement = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * MaxSpeed;
    Velocity.X = AHeroBase::MoveTowards(Velocity.X, DesiredMovement.X, Acceleration * DeltaTime);
    Velocity.Y = AHeroBase::MoveTowards(Velocity.Y, DesiredMovement.Y, Acceleration * DeltaTime);

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


    /*
    FVector Input = FVector(PlayerInput.X, PlayerInput.Y, 0);
    Input = Input.GetClampedToMaxSize(1.0f);
    const FVector DesiredVelocity = Input * MaxSpeed;
    
    const float Acceleration = AccelerationFactor * DeltaTime;
    Velocity.X = MoveTowards(Velocity.X, DesiredVelocity.X, Acceleration);
    Velocity.Y = MoveTowards(Velocity.Y, DesiredVelocity.Y, Acceleration);
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Velocity: %s"), *Velocity.ToString()));

    
    Root->AddForce(Velocity * Root->GetBodyInstance()->GetBodyMass());
     */
}
