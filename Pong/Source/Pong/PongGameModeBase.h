// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "Ball.h"

#include "PongGameModeBase.generated.h"

/**
 * Pong gameplay mode
 */
UCLASS()
class PONG_API APongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ClassNames)
	TSubclassOf<UUserProfile> UserProfileBP;

	virtual void BeginPlay() override;

	ABall* GetBall() const;
	void ResetBall();
	
protected:
	ABall* Ball;
	
};
