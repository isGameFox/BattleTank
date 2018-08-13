// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

class UTankBarrel;
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent(){
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet) {
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) const {
	auto TankName = GetName();
	if (!Barrel) {
		UE_LOG(LogTemp, Warning, TEXT("Aiming - No Barrel"))
		return;
	}
	FVector OutLaunchVelocity;
	FVector BarrelEnd = Barrel->GetSocketLocation(FName("BarrelEnd"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		BarrelEnd,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const{
	//Get difference between current barrel rotator and destination rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);

	if (abs(DeltaRotator.Yaw) > 180)
		DeltaRotator.Yaw = DeltaRotator.Yaw * -1;
	Turret->Rotate(DeltaRotator.Yaw);
}
