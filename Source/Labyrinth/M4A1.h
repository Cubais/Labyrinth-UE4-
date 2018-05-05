// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Projectile.h"
#include "WeaponAbstract.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "M4A1.generated.h"

UCLASS()
class LABYRINTH_API AM4A1 : public AWeaponAbstract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AM4A1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AProjectile> ToSpawnBullet;

	UFUNCTION()
		void Fire();
	UFUNCTION()
		void SpawnBullet();
	
};
