// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController: Begin Play"))

		ATank* PlayerTank = nullptr;
	PlayerTank = GetControlledTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - Tank: %s"), *(PlayerTank->GetName()))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - Tank Not Found!"))
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}


