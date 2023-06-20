// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/SubSystems/NGlobalAbilitiesSubsystem.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"

void UNGlobalAbilitiesSubsystem::RegisterGAS(UAbilitySystemComponent* InComponent)
{
	RegisteredAbilityComponents.Add(InComponent);
}

void UNGlobalAbilitiesSubsystem::UnregisterGAS(UAbilitySystemComponent* InComponent)
{
	RegisteredAbilityComponents.Remove(InComponent);
}
