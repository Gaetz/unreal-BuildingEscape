// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongStateBase.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API APongStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	APongStateBase();

	UFUNCTION()
	int32 GetPlayerScore() const;
	UFUNCTION()
	int32 GetOpponentScore() const;
	
	UFUNCTION()
	void SetPlayerScore(int32 ScoreP);
	UFUNCTION()
	void SetOpponentScore(int32 ScoreP);
	
	protected:
	void SetScore(int32 ScoreP, int32& ScoreToSet);

	UPROPERTY()
	int32 PlayerScore;

	UPROPERTY()
	int32 OpponentScore;
};
