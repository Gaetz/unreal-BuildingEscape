// Fill out your copyright notice in the Description page of Project Settings.


#include "Walls.h"

// Sets default values
AWalls::AWalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	BottomWall = CreateDefaultSubobject<UStaticMeshComponent>("BottomWall");
	TopWall = CreateDefaultSubobject<UStaticMeshComponent>("TopWall");
	const auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if(MeshAsset.Object != nullptr)
	{
		BottomWall->SetStaticMesh(MeshAsset.Object);
		TopWall->SetStaticMesh(MeshAsset.Object);
	}

	RootComponent = Root;
	BottomWall->SetupAttachment(Root);
	TopWall->SetupAttachment(Root);

	BottomWall->SetRelativeLocation(FVector(-50, 0, 500));
	BottomWall->SetRelativeScale3D(FVector(1, 20, 1));
	TopWall->SetRelativeLocation(FVector(-50, 0, -500));
	TopWall->SetRelativeScale3D(FVector(1, 20, 1));

}

// Called when the game starts or when spawned
void AWalls::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

