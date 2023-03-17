// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "MannyAnimInstanceProxy.generated.h"

class UMannyAnimInstance;

/**
 * 
 */
USTRUCT(BlueprintType)
struct NEVERMORE_API FMannyAnimInstanceProxy : public FAnimInstanceProxy
{
	GENERATED_BODY()

	FMannyAnimInstanceProxy();

	FMannyAnimInstanceProxy(UAnimInstance* Instance);

private:

	// This is a threshold that speed should overcome to consider character moving
	float MinimalSpeed{ 3.f };

	// Threshold that Velocity.Z should overcome for ABP consider character jumping
	float MinimalVelocityZ{ 100.f };

protected:
	/** Called before update so we can copy any data we need */
	virtual void PreUpdate(UAnimInstance* InAnimInstance, float DeltaSeconds) override;

public:

	// Is character falling?
	UPROPERTY(Transient, BlueprintReadOnly, EditAnywhere, Category = "Air Locomotion")
	bool bIsFalling{ false };

	// Character current velocity
	UPROPERTY(Transient, BlueprintReadOnly, EditAnywhere, Category = "Locomotion")
	FVector Velocity{ 0.f };

	// Character current acceleration
	UPROPERTY(Transient, BlueprintReadOnly, EditAnywhere, Category = "Locomotion")
	FVector Acceleration{ 0.f };

public:

	// Should character play locomotion animations?
	bool ShouldMove() const;

	// Get character speed along the ground
	float GetGroundSpeed() const;

	bool HasJumped() const;
};
