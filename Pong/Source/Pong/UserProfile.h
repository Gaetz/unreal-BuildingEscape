// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"

#include "UserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PONG_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= GameSettings)
	int PointsToWin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= GameSettings)
	float BallSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= GameSettings)
	FString UserName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Unit)
	TSubclassOf<UObject> UClassOfPlayer;

	UPROPERTY(EditAnywhere, meta=(MetaClass="GameMode"), Category=Unit)
	TSubclassOf<UObject> UClassGameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= HUD)
	FColoredTexture Texture;
};
