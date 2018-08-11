// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float ReticleXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float ReticleYLocation = 0.33333f;
	
private:
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
