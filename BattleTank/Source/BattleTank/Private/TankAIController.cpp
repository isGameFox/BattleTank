// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* PlayerTank = nullptr;
	PlayerTank = GetPlayerTank();

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - Found PlayerTank: %s"), *(PlayerTank->GetName()))
	} else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - PlayerTank Not Found!"))
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


