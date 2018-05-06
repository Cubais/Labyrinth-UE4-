// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAbstract.h"
#include "Engine.h"
#include "Components/CapsuleComponent.h"
#include <chrono>
#include <ctime>
#include "Components/MeshComponent.h"
#include "Projectile.h"
#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "EnemyParasite.generated.h"

UCLASS()
class LABYRINTH_API AEnemyParasite :public AEnemyAbstract
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyParasite();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	
	UFUNCTION(BlueprintCallable)
		void Hit(AActor* OtherActor);

private:
	std::chrono::system_clock::time_point start_animation;
	
};
