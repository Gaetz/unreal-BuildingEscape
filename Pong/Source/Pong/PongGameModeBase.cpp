// Copyright Epic Games, Inc. All Rights Reserved.


#include "PongGameModeBase.h"


void APongGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	/*
	APongGameModeBase* GameMode = Cast<APongGameModeBase>(GetWorld()->GetAuthGameMode());
	if(GameMode)
	{
		UUserProfile* UserProfile = NewObject<UUserProfile>(static_cast<UObject*>(GetTransientPackage()), UUserProfile::StaticClass());
	}
	*/
	
	// Spawn Ball
	const FTransform SpawnLocation;
	Ball = GetWorld()->SpawnActor<ABall>(ABall::StaticClass(), SpawnLocation);
}

ABall* APongGameModeBase::GetBall() const
{
	return Ball;
}

void APongGameModeBase::ResetBall()
{
	Ball->SetActorLocation(FVector::ZeroVector);
}

