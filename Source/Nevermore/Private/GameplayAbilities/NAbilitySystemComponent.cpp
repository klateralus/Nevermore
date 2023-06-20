// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/NAbilitySystemComponent.h"
#include "GameplayAbilities/SubSystems/NGlobalAbilitiesSubsystem.h"


void UNAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UNGlobalAbilitiesSubsystem* GlobalAbilities = UWorld::GetSubsystem<UNGlobalAbilitiesSubsystem>(GetWorld()))
	{
		GlobalAbilities->RegisterGAS(this);
	}
}

void UNAbilitySystemComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (UNGlobalAbilitiesSubsystem* GlobalAbilities = UWorld::GetSubsystem<UNGlobalAbilitiesSubsystem>(GetWorld()))
	{
		GlobalAbilities->UnregisterGAS(this);
	}
}
