// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupInterface.h"

#include "Pickup.generated.h"

UCLASS()
class VRPLAYGROUND_API APickup : public AActor, public IPickupInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	USceneComponent *Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	class UBoxComponent* Base;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	class UBoxComponent* InteractiveCollider;

	
public:	
	APickup();

protected:
	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup Interface")
		void Pickup(class UMotionControllerComponent *MotionController);

	virtual void Pickup_Implementation(class UMotionControllerComponent *MotionController) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup Interface")
		void Drop(class UMotionControllerComponent *MotionController);

	virtual void Drop_Implementation(class UMotionControllerComponent *MotionController) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	bool bUsing;

	bool bSimulatePhysics;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	class UMotionControllerComponent *CurrentMotionController;

};
