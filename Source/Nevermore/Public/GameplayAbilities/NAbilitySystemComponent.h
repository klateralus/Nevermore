// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "NAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class NEVERMORE_API UNAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
};
