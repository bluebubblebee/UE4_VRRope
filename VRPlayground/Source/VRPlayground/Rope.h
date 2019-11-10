// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Rope.generated.h"

/**
 * 
 */
UCLASS()
class VRPLAYGROUND_API ARope : public APickup
{
	GENERATED_BODY()

public:

	ARope();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cable")
	class UPhysicsConstraintComponent* ConstraintComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cable")
	class UCableComponent* CableComponent;

protected:

	// Extra cable lenght needed to detect that the cable has been pulled
	UPROPERTY(EditDefaultsOnly, Category = "Cable")
	float MinPullLength = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cable")
	bool bIsPulling;

	// Gets the length of the cable
	UFUNCTION(BlueprintCallable, Category = "Cable")
	float GetCableLength();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Cable")
	void OnPull();

	float InitialCableLength;

public:

	//// IPickupInterface Implementation ///
	virtual void Drop_Implementation(class UMotionControllerComponent *MotionController) override;

	virtual void Pickup_Implementation(class UMotionControllerComponent *MotionController) override;
	//// IPickupInterface Implementation ///
};
