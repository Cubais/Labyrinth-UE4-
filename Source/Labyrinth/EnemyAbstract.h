// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAbstract.generated.h"

UCLASS(Abstract)
class LABYRINTH_API AEnemyAbstract : public ACharacter
{
	GENERATED_BODY()

public:
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
		int Health; //value representing how many times needs to be hit to death

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsDeath;

	UFUNCTION(Category = "enemy")
		void Attack() PURE_VIRTUAL(AEnemyAbstract::Attack, ;);

	
	
};
