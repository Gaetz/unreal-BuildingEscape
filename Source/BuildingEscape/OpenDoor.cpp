// MIT Licence

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	IsDoorOpen = false;
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll trogger volume
	if(PressurePlate->IsOverlappingActor(ActorThatOpens) && !IsDoorOpen) 
	{
		OpenDoor();
		IsDoorOpen = true;
	}
	if(!(PressurePlate->IsOverlappingActor(ActorThatOpens)) && IsDoorOpen) 
	{
		CloseDoor();
		IsDoorOpen = false;
	}
}

void UOpenDoor::OpenDoor()
{
    AActor* Owner = GetOwner();
	FRotator Rotation = FRotator(OpenAngle, 0.0f, 0.0f);
	Owner->SetActorRotation(Rotation);
}

void UOpenDoor::CloseDoor()
{
    AActor* Owner = GetOwner();
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	Owner->SetActorRotation(Rotation);
}
