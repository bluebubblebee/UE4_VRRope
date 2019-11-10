// Fill out your copyright notice in the Description page of Project Settings.


#include "Rope.h"
#include "CableComponent.h"
#include "Components/BoxComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

ARope::ARope()
{	

	CableComponent = CreateDefaultSubobject<UCableComponent>(TEXT("CableComponent"));
	CableComponent->SetupAttachment(Root);

	ConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("ConstraintComponent"));
	ConstraintComponent->SetupAttachment(Root);

	PrimaryActorTick.bCanEverTick = true;
}


void ARope::BeginPlay()
{
	Super::BeginPlay();

	InitialCableLength = GetCableLength();
}

void ARope::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Checks if we are using this rope-pickup or not
	if (!bUsing) return;

	float CurrentCableLength = GetCableLength() - InitialCableLength;

	// Check if current cable length has reached the minimun
	if (!bIsPulling)
	{
		if (CurrentCableLength >= MinPullLength)
		{
			bIsPulling = true;

			// Call the blueprint event
			OnPull();

			Drop(CurrentMotionController);
		}
	}
}

float ARope::GetCableLength()
{
	// Length == Distance frrom the base (handle) to the constraint
	float length = FVector::Dist(ConstraintComponent->GetComponentLocation(), Base->GetComponentLocation());
	return length;
}



//// IPickupInterface Implementation ///
void ARope::Pickup_Implementation(class UMotionControllerComponent *MotionController)
{
	Super::Pickup_Implementation(MotionController);

	// Reset to default
	bIsPulling = false;

}

void ARope::Drop_Implementation(class UMotionControllerComponent *MotionController)
{
	Super::Drop_Implementation(MotionController);

	// Reset to default
	bIsPulling = false;
}

//// IPickupInterface Implementation ///
