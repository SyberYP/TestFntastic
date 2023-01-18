// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FT2AIController.generated.h"

UCLASS()
class FNTASTIC_TASK2_API AFT2AIController : public AAIController
{
    GENERATED_BODY()

public:
    void SetTargetPoint(AActor* Actor);
    void SetSpawnActor(AActor* SpawnActor);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
    FName FocusOnKeyName = "TargetPoint";

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
    FName NestActorKeyName = "NestActor";

private:
    AActor* ActorForFocus;
    AActor* GetFocusOnActor() const;
    AActor* TargetPoint;
    AActor* NestRef;

    void SetBlackboardValueAsObject(FName ActorKeyName, AActor* Actor);
};
