// Copyright Epic Games, Inc. All Rights Reserved.

#include "NevermoreGameMode.h"
#include "NevermoreCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANevermoreGameMode::ANevermoreGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
