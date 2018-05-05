// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Weapon.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UWeapon : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LABYRINTH_API IWeapon
{
	GENERATED_BODY()

protected:

	

		
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(Category = "Weapon")
		virtual void Fire() = 0;
	UFUNCTION(Category = "Weapon")
		virtual void SpawnBullet() = 0;

	
	
};
