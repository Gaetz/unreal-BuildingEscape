// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroBase.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AHeroBase::AHeroBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->InitSphereRadius(50.0f);
	Root->SetCollisionProfileName(TEXT("Pawn"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	ParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(Root);
}

// Called to bind functionality to input
void AHeroBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &AHeroBase::SetHorizontalInput);
	InputComponent->BindAxis("Vertical", this, &AHeroBase::SetVerticalInput);
}
