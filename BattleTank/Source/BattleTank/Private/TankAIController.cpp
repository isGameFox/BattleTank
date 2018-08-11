// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* PlayerTank = nullptr;
	PlayerTank = GetPlayerTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - PlayerTank Not Found!"))
	}
}

void ATankAIController::Tick(float DeltaTime) {
	ATank* ThisTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!ThisTank || !PlayerTank) { return; }
	ThisTank->AimAt(PlayerTank->GetActorLocation());
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


