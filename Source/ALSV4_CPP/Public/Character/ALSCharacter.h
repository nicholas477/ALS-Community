// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2021 Doğa Can Yanıkoğlu
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/dyanikoglu/ALSV4_CPP
// Original Author: Doğa Can Yanıkoğlu
// Contributors:    


#pragma once

#include "CoreMinimal.h"
#include "Character/ALSBaseCharacter.h"
#include "ALSCharacter.generated.h"

class UNoiseVisualizationComponent;

/**
 * Specialized character class, with additional features like held object etc.
 */
UCLASS(Blueprintable, BlueprintType)
class ALSV4_CPP_API AALSCharacter : public AALSBaseCharacter
{
	GENERATED_BODY()

public:
	AALSCharacter(const FObjectInitializer& ObjectInitializer);

	/** Implemented on BP to update held objects */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ALS|HeldObject")
	void UpdateHeldObject();

	virtual void UpdateHeldObject_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ALS|HeldObject")
	void ClearHeldObject();

	virtual void ClearHeldObject_Implementation() {};

	virtual ECollisionChannel GetThirdPersonTraceParams(FVector& TraceOrigin, float& TraceRadius) override;

	virtual FTransform GetThirdPersonPivotTarget() override;

	virtual FVector GetFirstPersonCameraTarget() override;

	void MakeNoise(float Loudness = 1.f, APawn* NoiseInstigator = nullptr, FVector NoiseLocation = FVector::ZeroVector, float MaxRange = 0.f, FName Tag = NAME_None);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Noise")
		UNoiseVisualizationComponent* NoiseVisualizationComponent;

private:
	bool bNeedsColorReset = false;
};
