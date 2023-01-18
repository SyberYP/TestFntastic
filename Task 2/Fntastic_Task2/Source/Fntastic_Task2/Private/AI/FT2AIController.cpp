// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/FT2AIController.h"
#include "AI/FT2AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

AActor* AFT2AIController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;
    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}

void AFT2AIController::SetTargetPoint(AActor* Actor)
{
    if (!Actor) return;
    TargetPoint = Actor;

    SetBlackboardValueAsObject(FocusOnKeyName, Actor);
}

void AFT2AIController::SetSpawnActor(AActor* SpawnActor)
{
    if (!SpawnActor) return;
    NestRef = SpawnActor;

    SetBlackboardValueAsObject(NestActorKeyName, NestRef);
}

void AFT2AIController::SetBlackboardValueAsObject(FName ActorKeyName, AActor* Actor)
{
    if (!GetBlackboardComponent()) return;

    GetBlackboardComponent()->SetValueAsObject(ActorKeyName, Actor);
}