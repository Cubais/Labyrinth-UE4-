// Fill out your copyright notice in the Description page of Project Settings.

#include "LabyrinthGameModeBase.h"
#include "Labyrinth.h"
#include "Engine.h"


void ALabyrinthGameModeBase::StartPlay() {

	Super::StartPlay();

	if (GEngine) {

		GEngine->AddOnScreenDebugMessage(-1,0.5f,FColor::Yellow,TEXT("HEllo Wrold"));

	}
	
}


