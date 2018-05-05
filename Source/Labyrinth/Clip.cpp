// Fill out your copyright notice in the Description page of Project Settings.

#include "Clip.h"
#include "Engine/EngineTypes.h"


// Sets default values
AClip::AClip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	ClipCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ClipComponent"));
	RootComponent = ClipCapsule;
	
	ClipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClipMesh"));
	
	
	ClipMesh->SetSimulatePhysics(false);
	//ClipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ClipMesh->bGenerateOverlapEvents = false;

	ClipCapsule->bGenerateOverlapEvents = true;
	ClipCapsule->OnComponentBeginOverlap.AddDynamic(this,&AClip::OnOverlapBegin);

}
void AClip::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// OtherActor is the actor that triggered the event. Check that is not ourself 
	if ((OtherActor == nullptr) || (OtherActor == this) || (OtherComp == nullptr))
		return;

	ALabyrinthHero* hero = Cast<ALabyrinthHero>(OtherActor);
	if (hero) {
		if (hero->PickupAmmo()) {
			Destroy();
		}
	}
	GEngine->AddOnScreenDebugMessage(-2, 15.0f, FColor::Red, TEXT("Overlap"));
	
}



// Called when the game starts or when spawned
void AClip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

