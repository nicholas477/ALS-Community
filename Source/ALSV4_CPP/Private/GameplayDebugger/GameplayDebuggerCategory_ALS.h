// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#if WITH_GAMEPLAY_DEBUGGER

#include "CoreMinimal.h"
#include "GameplayDebuggerCategory.h"

#include "Containers/Ticker.h"

class APlayerController;
class AActor;

class FGameplayDebuggerCategory_ALS : public FGameplayDebuggerCategory
{
public:
	FGameplayDebuggerCategory_ALS();

	virtual void OnGameplayDebuggerActivated() override;
	virtual void OnGameplayDebuggerDeactivated() override;

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

protected:
	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;

	bool Tick(float DeltaTime);
};

#endif // WITH_GAMEPLAY_DEBUGGER