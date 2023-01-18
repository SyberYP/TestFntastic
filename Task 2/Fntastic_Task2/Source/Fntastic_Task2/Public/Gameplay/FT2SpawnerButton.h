// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/FT2Button.h"
#include "FT2CoreTypes.h"
#include "FT2SpawnerButton.generated.h"

class UBehaviorTree;

UCLASS()
class FNTASTIC_TASK2_API AFT2SpawnerButton : public AFT2Button
{
    GENERATED_BODY()

public:
    virtual void Activate() override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FEffectsData EffectsData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    AActor* TargetPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    AActor* NestRef;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TSubclassOf<APawn> AIPawnClassForSpawn;

    UFUNCTION(BlueprintCallable)
    void SpawnAnimal();
};
