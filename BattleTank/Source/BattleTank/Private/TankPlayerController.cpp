// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Begin Play"))

	ATank* PlayerTank = nullptr;
	PlayerTank = GetControlledTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController - Tank: %s"), *(PlayerTank->GetName()))
	} else {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController - Tank Not Found!"))
	}
}

 ATank* ATankPlayerController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}
