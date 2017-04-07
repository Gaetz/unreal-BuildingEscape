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

    Owner = GetOwner();
	IsDoorOpen = false;
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll trogger volume
	if(PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		OpenDoor();
	}
	if(IsDoorOpen && (GetWorld()->GetTimeSeconds() - DoorLastOpenTime >= DoorCloseDelay) && !PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		CloseDoor();
	}
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(OpenAngle, 0.0f, 0.0f));
	DoorLastOpenTime = GetWorld()->GetTimeSeconds();
	IsDoorOpen = true;
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	IsDoorOpen = false;
}
