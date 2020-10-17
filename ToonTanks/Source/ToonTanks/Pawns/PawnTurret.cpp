// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"

#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

void APawnTurret::BeginPlay()
{
    Super::BeginPlay();
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

void APawnTurret::CheckFireCondition()
{
    if(!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
    {
        return;
    }
    if(DistanceToPlayer() <= FireRange)
    {
        Fire();
    }
}

float APawnTurret::DistanceToPlayer() const
{
    if(!PlayerPawn)
    {
        return 0.0f;
    }
    const float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
    return Distance;
}

// Called every frame
void APawnTurret::Tick(const float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(!PlayerPawn || DistanceToPlayer() > FireRange)
    {
        return;
    }
    RotateTurret(PlayerPawn->GetActorLocation());
}