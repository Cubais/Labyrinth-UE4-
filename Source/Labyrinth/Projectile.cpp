// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Engine.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	
	ProjectileMovementComponent->InitialSpeed = 5000;
	ProjectileMovementComponent->MaxSpeed = 5000;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::Fire(const FVector& shootDirection)
{
	ProjectileMovementComponent->Velocity =shootDirection * ProjectileMovementComponent->InitialSpeed;
	
}

