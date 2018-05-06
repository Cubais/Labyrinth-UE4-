// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyParasite.h"


// Sets default values
AEnemyParasite::AEnemyParasite()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	/*ParasiteCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("kok"));
	ParasiteMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("kok2"));

	

	RootComponent = ParasiteCapsule;
	//GetMesh()->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	ParasiteMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	ParasiteCapsule->bGenerateOverlapEvents = true;
	ParasiteCapsule->SetCapsuleHalfHeight(100.0);
	ParasiteCapsule->SetCapsuleRadius(40.0);

	ParasiteCapsule->OnComponentBeginOverlap.AddDynamic(this, &AEnemyParasite::OnOverlapBegin);*/
		
	

}

// Called when the game starts or when spawned
void AEnemyParasite::BeginPlay()
{
	Super::BeginPlay();
	IsDeath = false;
	Health = 10;
	
}

// Called every frame
void AEnemyParasite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsDeath) {
		auto end_animation = std::chrono::system_clock::now();
		std::chrono::duration<double> animation_done = end_animation - start_animation;
		if (animation_done.count() > 4.6) Destroy();
	}

}

// Called to bind functionality to input
void AEnemyParasite::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AEnemyParasite::Hit(AActor* OtherActor) {

	if ((OtherActor == nullptr) || (OtherActor == this))
		return;

	if (IsDeath) return;

	AProjectile* proj = Cast<AProjectile>(OtherActor);
	if (proj) {

		GEngine->AddOnScreenDebugMessage(-2, 15.0f, FColor::Blue, TEXT("KOk"));
		Health--;
		if (Health == 0) {
			IsDeath = true;
			start_animation = std::chrono::system_clock::now();
		}
	}

}

