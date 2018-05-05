// Fill out your copyright notice in the Description page of Project Settings.

#include "M4A1.h"
#include "Engine.h"


// Sets default values
AM4A1::AM4A1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));

	fireRate = 0.1; // 10 bullets per second

	ammoCapacity = 25; // ammo in one clip

	numberOfClips = 4;
	
}

// Called when the game starts or when spawned
void AM4A1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AM4A1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AM4A1::Fire()
{
	SpawnBullet();
	
}

void AM4A1::SpawnBullet() {

	//check if SpawnBullet class is set
	if (ToSpawnBullet) {	

		UWorld* world = GetWorld();
		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			//spawn projectile on the position of socket "Muzzle" from WeaponMesh
			AProjectile* Projectile = world->SpawnActor<AProjectile>(ToSpawnBullet,WeaponMesh->GetSocketTransform(TEXT("Muzzle"),ERelativeTransformSpace::RTS_World), spawnParams);
			if (Projectile) {
				//Fire projectile
				Projectile->Fire(WeaponMesh->GetSocketRotation(TEXT("Muzzle")).Vector());				
				
			}
			

		}
	}

}

