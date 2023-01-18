// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/TargetPoint.h"
#include "FT2CoreTypes.h"
#include "Fntastic_Task2GameModeBase.generated.h"

class AAIController;
class UBehaviorTree;

UCLASS()
class FNTASTIC_TASK2_API AFntastic_Task2GameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AFntastic_Task2GameModeBase();

    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

    void SpawnBot(FTransform SpawnTransform, AActor* TargetPoint, UBehaviorTree* BehaviorTreeAsset, TSubclassOf<APawn> AIPawnClassForSpawn,
        AActor* SpawnActor, FEffectsData EffectsData);

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

private:
    TSubclassOf<APawn> CurrentAIPawnClass;
};
