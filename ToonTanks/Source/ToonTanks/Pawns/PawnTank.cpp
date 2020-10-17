// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

void APawnTank::ComputeMoveInput(const float Value)
{
    MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::ComputeRotateInput(const float Value)
{
    const float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
    const FRotator Rotation = FRotator(0, RotateAmount, 0);
    RotateDirection = FQuat(Rotation);
}

void APawnTank::Move()
{
    AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
    AddActorLocalRotation(RotateDirection, true);
}

APawnTank::APawnTank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
    Super::BeginPlay();
    PLayerController = Cast<APlayerController>(GetController());
    bIsPlayerAlive = true;
}

void APawnTank::HandleDestruction()
{
    Super::HandleDestruction();
    bIsPlayerAlive = false;
    SetActorHiddenInGame(true);
    SetActorTickEnabled(false);
}

bool APawnTank::GetIsPlayerAlive() const
{
    return bIsPlayerAlive;
}

// Called every frame
void APawnTank::Tick(const float DeltaTime)
{
    Super::Tick(DeltaTime);
    Rotate();
    Move();

    if(PLayerController)
    {
        FHitResult TraceHitResult;
        PLayerController->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);;
        const FVector HitLocation = TraceHitResult.ImpactPoint;
        RotateTurret(HitLocation);
    }
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::ComputeMoveInput);
    PlayerInputComponent->BindAxis("Turn", this, &APawnTank::ComputeRotateInput);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
}
