// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "NiagaraComponent.h"

// Sets default values
AHero::AHero() : AHeroBase()
{
}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector2D Input = PlayerInput;
	Input.Normalize();
	// Speed
	const FVector Acceleration = FVector(Input.X, Input.Y, 0.0f) * AccelerationFactor;
	Velocity += Acceleration * DeltaTime;
	Velocity = FVector(FMath::Clamp(Velocity.X, -MaxSpeed, MaxSpeed), FMath::Clamp(Velocity.Y, -MaxSpeed, MaxSpeed), 0.0f);
	// Location
	const FVector Translation = Velocity * DeltaTime;
	const FVector Location = GetActorLocation();
	FVector NewLocation = Location + Translation;
	// Collisions
	const float LowerBound = Bounds.GetLowerBoundValue();
	const float UpperBound = Bounds.GetUpperBoundValue();
	NewLocation = FVector(FMath::Clamp(NewLocation.X, LowerBound, UpperBound), FMath::Clamp(NewLocation.Y, LowerBound, UpperBound), 0.0f);
	if(NewLocation.X <= LowerBound || NewLocation.X >= UpperBound)
	{
		Velocity.X = -Velocity.X * Bounciness;
	}
	if(NewLocation.Y <= LowerBound || NewLocation.Y >= UpperBound)
	{
		Velocity.Y = -Velocity.Y * Bounciness;
	}
	
	SetActorRelativeLocation(NewLocation);
}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("Horizontal", this, &AHero::SetHorizontalInput);
	InputComponent->BindAxis("Vertical", this, &AHero::SetVerticalInput);
}

