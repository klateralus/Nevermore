// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MannyAnimInstance.generated.h"

class UCharacterMovementComponent;
struct FMannyAnimInstanceProxy;

/**
 * UMannyAnimInstance implements native thread-safe logic evaluation for animation blueprint 'ABP_Manny'.
 * Usage of the native class instead of AnimationBlueprint provides x10-15 performance boost.
 * Usage of a thread-safe approach allows context relevant evaluations to be done on worker threads and not on main thread.
 */
UCLASS(Transient, Blueprintable)
class NEVERMORE_API UMannyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	UCharacterMovementComponent* MovementComponent{nullptr};

	// Is character falling?
	bool bIsFalling{ false };

	// Character current velocity
	FVector Velocity{ 0.f };

	// Character current acceleration
	FVector Acceleration{ 0.f };

public:
	UMannyAnimInstance();

	/**
	 * Called after the C++ constructor and after the properties have been initialized, including those loaded from config.
	 * This is called before any serialization or other setup has happened.
	 */
	virtual void PostInitProperties() override;

	// Native initialization override point
	virtual void NativeInitializeAnimation() override;

	// Native update override point. It is usually a good idea to simply gather data in this step and 
	// for the bulk of the work to be done in NativeThreadSafeUpdateAnimation.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	/** Override point for derived classes to create their own proxy objects (allows custom allocation) */
	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override;

	/** Override point for derived classes to destroy their own proxy objects (allows custom allocation) */
	virtual void DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy) override;

	friend struct FMannyAnimInstanceProxy;

public:

	// Threshold that speed should overcome for ABP to consider character moving
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "Locomotion")
	float MinimalSpeed{ 3.f };

	// Threshold that Velocity.Z should overcome for ABP consider character jumping
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "Locomotion")
	float MinimalVelocityZ{ 100.f };

public:

	// Get Anim Instance Proxy for a thread safe logic evaluation
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Optimization", meta = (BlueprintThreadSafe))
	const FMannyAnimInstanceProxy& GetMannyAnimInstanceProxy() const;

	// Should character play locomotion animations?
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Locomotion", meta = (BlueprintThreadSafe))
	bool ShouldMove() const;

	// Should character stop locomotion animations?
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Locomotion", meta = (BlueprintThreadSafe))
	bool ShouldNotMove() const { return !ShouldMove(); };

	// Get character speed along the ground
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Locomotion", meta = (BlueprintThreadSafe))
	float GetGroundSpeed() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Air Locomotion", meta = (BlueprintThreadSafe))
	bool HasJumped() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Air Locomotion", meta = (BlueprintThreadSafe))
	bool IsNotFalling() const;
};
