// Fill out your copyright notice in the Description page of Project Settings.


#include "OutTrigger.h"

#include "PongGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOutTrigger::AOutTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(50, 50, 500));
}

// Called when the game starts or when spawned
void AOutTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOutTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOutTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	const auto Message = FString::Printf(TEXT("%s entered"), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Turquoise, Message);

	APongGameModeBase* GameMode = Cast<APongGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode != nullptr)
	{
		GameMode->ResetBall();
	}
}

