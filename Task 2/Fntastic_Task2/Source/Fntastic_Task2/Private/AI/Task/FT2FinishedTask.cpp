// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/FT2FinishedTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "AI/FT2AICharacter.h"

UFT2FinishedTask::UFT2FinishedTask()
{
    NodeName = "TargetPoint";
}

EBTNodeResult::Type UFT2FinishedTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    if (!Controller || !Blackboard) return EBTNodeResult::Failed;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn) return EBTNodeResult::Failed;

    const auto NavSys = UNavigationSystemV1::GetCurrent(Pawn);
    if (!NavSys) return EBTNodeResult::Failed;

    FNavLocation NavLocation;
    auto SelfLocation = Pawn->GetActorLocation();

    const auto TargetActor = Cast<AActor>(Blackboard->GetValueAsObject(TargetPointKeyName));
    if (!TargetActor) return EBTNodeResult::Failed;

    auto TargetPointLocation = TargetActor->GetActorLocation();
    FVector Distance = SelfLocation - TargetPointLocation;
    if (Distance.IsNearlyZero(Radius))
    {
        const auto FT2AICharacter = Cast<AFT2AICharacter>(Pawn);
        if (!FT2AICharacter) EBTNodeResult::Failed;

        FT2AICharacter->ActivateFinished();
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}