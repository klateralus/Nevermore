// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "NGlobalAbilitiesSubsystem.generated.h"

class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class NEVERMORE_API UNGlobalAbilitiesSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	TSet<TObjectPtr<UAbilitySystemComponent>> RegisteredAbilityComponents;

public:
	void RegisterGAS(UAbilitySystemComponent* InComponent);
	void UnregisterGAS(UAbilitySystemComponent* InComponent);
};
