// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPickupInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VRPLAYGROUND_API IPickupInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup Interface")
	void Pickup(class UMotionControllerComponent *MotionController);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup Interface")
	void Drop(class UMotionControllerComponent *MotionController);

};
