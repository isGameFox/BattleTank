// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	ATank* ThisTank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!ThisTank || !PlayerTank) { return; }
	ThisTank->AimAt(PlayerTank->GetActorLocation());
	ThisTank->Fire();
}


