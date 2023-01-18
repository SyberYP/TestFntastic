// Copyright Epic Games, Inc. All Rights Reserved.

#include "Fntastic_Task2GameModeBase.h"
#include "Player/FT2PlayerController.h"
#include "Player/FT2Pawn.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "AI/FT2AIController.h"
#include "AI/FT2AICharacter.h"
#include "BehaviorTree/BehaviorTree.h"

AFntastic_Task2GameModeBase::AFntastic_Task2GameModeBase()
{
    PlayerControllerClass = AFT2PlayerController::StaticClass();
    DefaultPawnClass = AFT2Pawn::StaticClass();
}

UClass* AFntastic_Task2GameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    if (InController && InController->IsA<AAIController>())
    {
        return CurrentAIPawnClass;
    }
    return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void AFntastic_Task2GameModeBase::SpawnBot(FTransform SpawnTransform, AActor* TargetPoint, UBehaviorTree* BehaviorTreeAsset,
    TSubclassOf<APawn> AIPawnClassForSpawn, AActor* SpawnActor, FEffectsData EffectsData)
{
    CurrentAIPawnClass = AIPawnClassForSpawn;
    FActorSpawnParameters SpawnInfo;
    SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    const auto FT2AIController = GetWorld()->SpawnActor<AFT2AIController>(AIControllerClass, SpawnInfo);
    RestartPlayerAtTransform(FT2AIController, SpawnTransform);

    const auto FT2AICharacter = Cast<AFT2AICharacter>(FT2AIController->GetPawn());
    if (!FT2AICharacter) return;

    FT2AICharacter->SetBehaviorTreeAsset(BehaviorTreeAsset);
    FT2AICharacter->SetEffectsData(EffectsData);
    FT2AICharacter->ActivateStart();

    FT2AIController->RunBehaviorTree(BehaviorTreeAsset);
    FT2AIController->SetTargetPoint(TargetPoint);
    FT2AIController->SetSpawnActor(SpawnActor);
}
