// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FT2CoreTypes.h"
#include "FT2AICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class FNTASTIC_TASK2_API AFT2AICharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AFT2AICharacter();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void ActivateFinished();
    void ActivateStart();

    void SetBehaviorTreeAsset(UBehaviorTree* BTAsset) { BehaviorTreeAsset = BTAsset; }
    UBehaviorTree* GetBehaviorTreeAsset() const { return BehaviorTreeAsset; }

    void SetEffectsData(FEffectsData Data) { EffectsData = Data; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

private:
    FEffectsData EffectsData;
};
