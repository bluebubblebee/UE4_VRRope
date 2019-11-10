// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "MotionControllerComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APickup::APickup()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Base = CreateDefaultSubobject<UBoxComponent>(TEXT("Base"));
	Base->SetSimulatePhysics(true);
	Base->SetBoxExtent(FVector(1, 1, 1));
	Base->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Base->SetupAttachment(Root);

	InteractiveCollider = CreateDefaultSubobject < UBoxComponent>(TEXT("InteractiveCollider"));
	InteractiveCollider->SetupAttachment(Base);

	bUsing = false;

	PrimaryActorTick.bCanEverTick = true;

}


void APickup::BeginPlay()
{
	Super::BeginPlay();

	bSimulatePhysics = Base->IsSimulatingPhysics();	
}


void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APickup::Pickup_Implementation(UMotionControllerComponent* MotionController)
{
	if (!bUsing)
	{
		bUsing = true;

		CurrentMotionController = MotionController;

		Base->SetSimulatePhysics(false);
		Base->AttachToComponent(MotionController, FAttachmentTransformRules::KeepWorldTransform, NAME_None);
	}
}

void APickup::Drop_Implementation(UMotionControllerComponent* MotionController)
{
	if ((MotionController == nullptr) || (CurrentMotionController == MotionController))
	{
		bUsing = false;

		Base->SetSimulatePhysics(bSimulatePhysics);

		CurrentMotionController = nullptr;

		Base->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	}

}

