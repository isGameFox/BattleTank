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
		//if hits
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const{
	OutHitLocation = FVector(1.0);
	return false;
	/*
		const FHitResult UGrabber::GetFirstPhysicsBodyInReach() {
			SetPlayerViewpoint();

			//setup query params
			FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());
			FVector LineTraceEnd = PlayerLocation + (PlayerRotation.Vector() * Reach);

			//raycast to reach distance
			FHitResult Hit;
			GetWorld()->LineTraceSingleByObjectType(OUT Hit, PlayerLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

			AActor* ActorHit = Hit.GetActor();
			if (ActorHit) {
				UE_LOG(LogTemp, Warning, TEXT("Grabber detects: %s"), *(ActorHit->GetName()));
			}

			return Hit;
		}

		void UGrabber::SetPlayerViewpoint() {
			GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);
		}
	*/
}
