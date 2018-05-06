// Fill out your copyright notice in the Description page of Project Settings.


#include "LabyrinthHero.h"
#include <chrono>
#include "Engine.h"
#include "M4A1.h"




// Sets default values
ALabyrinthHero::ALabyrinthHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HeroMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeroMesh"));

	 
		
}

// Called when the game starts or when spawned
void ALabyrinthHero::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();		
 

}

// Called every frame
void ALabyrinthHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsReloading) {
		auto end_animation = std::chrono::system_clock::now();
		std::chrono::duration<double> animation_done = end_animation - start_animation;
		if (animation_done.count() > 2.3) StopReload();
	}

	if (isFiring) Fire();


}

// Called to bind functionality to input
void ALabyrinthHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ALabyrinthHero::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALabyrinthHero::MoveRight);

	PlayerInputComponent->BindAxis("Turn",this, &ALabyrinthHero::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ALabyrinthHero::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump",IE_Pressed,this, &ALabyrinthHero::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ALabyrinthHero::StopJump);

	PlayerInputComponent->BindAction("Fire",IE_Pressed,this,&ALabyrinthHero::Fire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ALabyrinthHero::StopFire);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ALabyrinthHero::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ALabyrinthHero::StopCrouch);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ALabyrinthHero::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ALabyrinthHero::StopSprint);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ALabyrinthHero::Reload);
	//PlayerInputComponent->BindAction("Reload", IE_Released, this, &ALabyrinthHero::StopReload);

	PlayerInputComponent->BindAction("AimDownSights", IE_Pressed, this, &ALabyrinthHero::AimDownSightsOn);
	PlayerInputComponent->BindAction("AimDownSights", IE_Released, this, &ALabyrinthHero::AimDownSightsOff);

}

void ALabyrinthHero::SpawnWeapon()
{
	//ak je nastavena zbran ktora sa ma spawnut
	if (ToSpawn) {

		UWorld* world = GetWorld();
		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			FRotator Rotation(0,0,0);
			FVector Location(0,0,0);

			//spawn actor od M4A1
			Weapon = world->SpawnActor<AM4A1>(ToSpawn, Location, Rotation, spawnParams);
			//attach weapon to mesh of this character to Socket Called Weapon_Attach
			Weapon->AttachToComponent((USceneComponent*)GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("Weapon_Attach"));
			ammo = Weapon->ammoCapacity;
			total_ammo = Weapon->numberOfClips*Weapon->ammoCapacity;

		}
	}
}

void ALabyrinthHero::MoveForward(float value) {

	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction,value);
	
}

void ALabyrinthHero::MoveRight(float value) {

	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

void ALabyrinthHero::StartCrouch()
{
	if (IsSprinting) {

		IsSprinting = false;
	}

	IsCrouching = true;
	HeroMovement->MaxWalkSpeed = 300.0f;
	
	
	
}
void ALabyrinthHero::StopCrouch()
{

	IsCrouching = false;	
	HeroMovement->MaxWalkSpeed = 600.0f;

	
}

void ALabyrinthHero::StartSprint() {

	if (IsCrouching) {
		//GEngine->AddOnScreenDebugMessage(-2, 15.0f, FColor::Red, TEXT("IsCrouching == true"));
		IsCrouching = false;

	}
	IsSprinting = true;
	HeroMovement->MaxWalkSpeed = 1000.0f;
	
}

void ALabyrinthHero::StopSprint() {

	IsSprinting = false;
	HeroMovement->MaxWalkSpeed = 600.0f;
}

void ALabyrinthHero::StartJump() {

	bPressedJump = true;
}

void ALabyrinthHero::StopJump() {

	bPressedJump = false;
}

void ALabyrinthHero::Fire()
{
	auto attempt_to_fire = std::chrono::system_clock::now();
	std::chrono::duration<double> can_fire = attempt_to_fire - bullet_fire_time;

	if ((ammo > 0) && (can_fire.count() > Weapon->fireRate) && !IsSprinting && !IsReloading) {
		isFiring = true;
		Weapon->Fire();
		
		bullet_fire_time = std::chrono::system_clock::now();
		ammo--;
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("ammo %d"), Weapon->ammoCapacity));
	
	

}

void ALabyrinthHero::StopFire() {
	isFiring = false;
}

void ALabyrinthHero::Reload() {	
		
	if (IsReloading) return;
	if (total_ammo == 0 || ammo == Weapon->ammoCapacity) return;

	IsReloading = true;
	
    start_animation = std::chrono::system_clock::now();

	
}

void ALabyrinthHero::StopReload() {

	IsReloading = false;
	if (total_ammo == 0) return;
	if (total_ammo >= Weapon->ammoCapacity) {

		int diffAmmo = Weapon->ammoCapacity - ammo;
		total_ammo -= diffAmmo;
		ammo += diffAmmo;
	}
	else {
		int diffAmmo = Weapon->ammoCapacity - ammo;
		if (diffAmmo >= total_ammo) {
			ammo += total_ammo;
			total_ammo = 0;
		}
		else {
			ammo += diffAmmo;
			total_ammo -= diffAmmo;
		}
	}
	

}

void ALabyrinthHero::AimDownSightsOn() {

	IsAiming = true;
	HeroMovement->MaxWalkSpeed = 600.0f;
	
}
void ALabyrinthHero::AimDownSightsOff() {
	
	IsAiming = false;
	HeroMovement->MaxWalkSpeed = 600.0f;

}
bool ALabyrinthHero::PickupAmmo() { //true if wee can store some ammo, otherwise false

	int max_ammo = Weapon->numberOfClips*Weapon->ammoCapacity;
	if (total_ammo == max_ammo) return false;

	total_ammo += Weapon->ammoCapacity;
	

	
	if (total_ammo > max_ammo) {
		total_ammo = max_ammo;

	}

	return true;
}