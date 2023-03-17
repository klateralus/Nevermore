// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MannyAnimData.generated.h"


/**
 * This structure is used to exchange data between AnimInstance and AnimInstanceProxy
 * The exchanges happens by using memcpy from from AnimInstance's Data to AnimInstanceProxy's Data in 'PreUpdate'
 * and from AnimInstanceProxy's Data to AnimInstance's Data in 'PostUpdate'
 */
USTRUCT()
struct NEVERMORE_API FMannyAnimData
{
	GENERATED_BODY()

	// Is character falling?
	bool bIsFalling{ false };

	// Character current velocity
	FVector Velocity{ 0.f };

	// Character current acceleration
	FVector Acceleration{ 0.f };
};
