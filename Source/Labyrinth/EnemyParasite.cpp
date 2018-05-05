// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyParasite.h"


// Sets default values
AEnemyParasite::AEnemyParasite()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ParasiteCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("kok"));
	
	RootComponent = ParasiteCapsule;
	
	ParasiteCapsule->bGenerateOverlapEvents = true;
	ParasiteCapsule->SetCapsuleHalfHeight(100.0);
	ParasiteCapsule->SetCapsuleRadius(40.0);

	ParasiteCapsule->OnComponentBeginOverlap.AddDynamic(this, &AEnemyParasite::OnOverlapBegin);
		
	

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

void AEnemyParasite::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if ((OtherActor == nullptr) || (OtherActor == this) || (OtherComp == nullptr))
		return;

	

		GEngine->AddOnScreenDebugMessage(-2, 15.0f, FColor::Blue, TEXT("FFFFF"));
	
}

