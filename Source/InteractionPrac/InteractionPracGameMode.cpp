// Copyright Epic Games, Inc. All Rights Reserved.

#include "InteractionPracGameMode.h"
#include "InteractionPracCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInteractionPracGameMode::AInteractionPracGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
