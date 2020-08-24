// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall() : Speed(-400)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if(MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

	Collider = CreateDefaultSubobject<UBoxComponent>("Collider");
	
    const FVector MeshSize = Mesh->CalcBounds(GetTransform()).BoxExtent;
	Collider->SetBoxExtent(MeshSize);

	RootComponent = Root;
	Mesh->SetupAttachment(Root);
	Collider->SetupAttachment(Root);
}

void ABall::SetSpeed(float SpeedP)
{
	Speed = SpeedP;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector const Location = GetActorLocation();
	auto const NewLocation = Location + FVector(0, Speed * DeltaTime, 0);
	SetActorLocation(NewLocation);
}

