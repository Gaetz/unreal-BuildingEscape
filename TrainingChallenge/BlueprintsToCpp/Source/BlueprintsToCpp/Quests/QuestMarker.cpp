// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	ParticleSystemComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	
	SetRootComponent(Root);
	ParticleSystemComp->SetupAttachment(Root);
}

void AQuestMarker::BeginPlay()
{
	RefreshVisibility();
	GetQuestManager()->CompletedQuest.AddDynamic(this, &AQuestMarker::QuestUpdate);
}

void AQuestMarker::RefreshVisibility()
{
	FQuestInfo Quest = GetQuestManager()->GetQuest(QuestName);
	const bool Visiblility = GetQuestManager()->IsActiveQuest(QuestName) && Quest.Progress == ShowAtProgress;
	ParticleSystemComp->SetVisibility(Visiblility);
}

void AQuestMarker::QuestUpdate(int32 Index)
{
	RefreshVisibility();
}



