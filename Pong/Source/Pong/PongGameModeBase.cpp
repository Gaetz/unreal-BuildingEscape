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
	FTransform SpawnLocation;
	SpawnLocation.AddToTranslation(FVector(-60, 0, 0));
	Ball = GetWorld()->SpawnActor<ABall>(ABall::StaticClass(), SpawnLocation);
}

ABall* APongGameModeBase::GetBall() const
{
	return Ball;
}

void APongGameModeBase::ResetBall()
{
	auto Location = Ball->GetActorLocation();
	Location.Y = 0;
	Location.Z = 0;
	Ball->SetActorLocation(Location);
}

