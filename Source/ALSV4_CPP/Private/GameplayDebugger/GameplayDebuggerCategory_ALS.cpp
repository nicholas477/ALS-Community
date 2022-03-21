// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayDebugger/GameplayDebuggerCategory_ALS.h"

#if WITH_GAMEPLAY_DEBUGGER

#include "Components/ALSDebugComponent.h"

FGameplayDebuggerCategory_ALS::FGameplayDebuggerCategory_ALS()
{
}

void FGameplayDebuggerCategory_ALS::OnGameplayDebuggerActivated()
{
    TickDelegate = FTickerDelegate::CreateSP(this, &FGameplayDebuggerCategory_ALS::Tick);
    TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

void FGameplayDebuggerCategory_ALS::OnGameplayDebuggerDeactivated()
{
    FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);

    UALSDebugComponent::SetDebugView(false);
    UALSDebugComponent::SetShowTraces(false);
    UALSDebugComponent::SetShowDebugShapes(false);
    UALSDebugComponent::SetShowLayerColors(false);
}

bool FGameplayDebuggerCategory_ALS::Tick(float DeltaTime)
{
    UALSDebugComponent::SetDebugView(IsCategoryEnabled());
    UALSDebugComponent::SetShowTraces(IsCategoryEnabled());
    UALSDebugComponent::SetShowDebugShapes(IsCategoryEnabled());
    UALSDebugComponent::SetShowLayerColors(IsCategoryEnabled());

    return true;
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_ALS::MakeInstance()
{
    return MakeShareable(new FGameplayDebuggerCategory_ALS());
}

#endif // WITH_GAMEPLAY_DEBUGGER