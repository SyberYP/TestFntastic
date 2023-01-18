// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FT2FinishedTask.generated.h"

UCLASS()
class FNTASTIC_TASK2_API UFT2FinishedTask : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UFT2FinishedTask();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float Radius = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FName TargetPointKeyName = "TargetPoint";
};
