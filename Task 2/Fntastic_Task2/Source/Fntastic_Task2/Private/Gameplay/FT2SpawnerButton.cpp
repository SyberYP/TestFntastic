// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/FT2SpawnerButton.h"
#include "Fntastic_Task2/Fntastic_Task2GameModeBase.h"
#include "BehaviorTree/BehaviorTree.h"


void AFT2SpawnerButton::Activate()
{
    SpawnAnimal();
}

void AFT2SpawnerButton::SpawnAnimal()
{
    if (!GetWorld()) return;

    const auto GameMode = Cast<AFntastic_Task2GameModeBase>(GetWorld()->GetAuthGameMode());
    if (!GameMode) return;

    if (!NestRef) NestRef = this;
    GameMode->SpawnBot(
        NestRef->GetActorTransform(), TargetPoint, BehaviorTreeAsset, AIPawnClassForSpawn, NestRef, EffectsData);
}
