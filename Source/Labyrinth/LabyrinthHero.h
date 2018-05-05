// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include <chrono>
#include <ctime>
#include "Camera/CameraComponent.h"
#include "WeaponAbstract.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "LabyrinthHero.generated.h"

UCLASS()
class LABYRINTH_API ALabyrinthHero : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALabyrinthHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* HeroMesh;
	
	//blueprints subclass of M4A1
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AM4A1> ToSpawn;
		
	UFUNCTION()
		void SpawnWeapon();
	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
		void StartCrouch();

	UFUNCTION()
		void StopCrouch();

	UFUNCTION()
		void StartJump();

	UFUNCTION()
		void StartSprint();

	UFUNCTION()
		void StopSprint();

	UFUNCTION()
		void StopJump();
	UFUNCTION()
		void Fire();
	UFUNCTION()
		void StopFire();
	UFUNCTION()
		void Reload();
	UFUNCTION()
		void StopReload();
	UFUNCTION()
		void AimDownSightsOn();
	UFUNCTION()
		void AimDownSightsOff();
	//visible to blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsCrouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsReloading;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsAiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float armor = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float health = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ammo; // ammo in current clip

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int total_ammo; //ammo in all clips

	bool PickupAmmo();

	

	
	UCharacterMovementComponent* HeroMovement = GetCharacterMovement();
	
	
		
private:

	AWeaponAbstract* Weapon;
	bool isFiring;
	
	std::chrono::system_clock::time_point bullet_fire_time;
	std::chrono::system_clock::time_point start_animation;

	
	
};
