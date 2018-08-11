// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	ATank* PlayerTank = nullptr;
	PlayerTank = GetControlledTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController - Tank Not Found!"))
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const{
	
	//get location of the aim reticle
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ReticleScreenLocation = FVector2D(ViewportSizeX*ReticleXLocation, ViewportSizeY*ReticleYLocation);
	
	FVector WorldDirection;
	if (GetLookDirection(ReticleScreenLocation, WorldDirection)) {
		if (GetLookVectorHitLocation(OutHitLocation, WorldDirection)) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const{
	FHitResult Hit;
	FVector PlayerLocation;
	FRotator PlayerRotation;

	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (LookDirection * LineTraceRange);
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility, TraceParams)) {
		HitLocation = Hit.Location;
		return true;
	}
	else {
		return false;
	}
}
