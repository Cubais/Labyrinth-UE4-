// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponAbstract.generated.h"

UCLASS(Abstract)
class LABYRINTH_API AWeaponAbstract : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	//AWeaponAbstract();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		float fireRate;

	UPROPERTY()
		int ammoCapacity;

	UPROPERTY()
		int numberOfClips;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Category = "Weapon")
		virtual void Fire() PURE_VIRTUAL(AWeaponAbstract::Fire, ;);
	UFUNCTION(Category = "Weapon")
		virtual void SpawnBullet() PURE_VIRTUAL(AWeaponAbstract::SpawnBullet, ;);

	
	
};
