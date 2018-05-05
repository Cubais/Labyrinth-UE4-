// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyParasite.h"


// Sets default values
AEnemyParasite::AEnemyParasite()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	//RootComponent = ParasiteCapsule;

	/*ParasiteCapsule->bGenerateOverlapEvents = true;

	ParasiteCapsule->OnComponentBeginOverlap.AddDynamic(this, &AEnemyParasite::OnOverlapBegin);*/
		

}

// Called when the game starts or when spawned
void AEnemyParasite::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyParasite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyParasite::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

