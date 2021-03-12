// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavigationSystemCPPGameMode.h"
#include "NavigationSystemCPPPlayerController.h"
#include "NavigationSystemCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANavigationSystemCPPGameMode::ANavigationSystemCPPGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ANavigationSystemCPPPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}