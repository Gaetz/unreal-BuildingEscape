// MIT Licence

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY(EditAnywhere)
    float OpenAngle = 90.0f;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;

    UPROPERTY(EditAnywhere)
    AActor* ActorThatOpens;

    // Time after which door closes
    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 1.0f;

    // Time after which door closes
    float DoorLastOpenTime;

    // True when door is open
    bool IsDoorOpen;

    // Component's owner
    AActor* Owner;

    // Open door when triggered
    void OpenDoor();

    // Close door when triggered
    void CloseDoor();
};
