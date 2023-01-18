// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TargetPoint.h"
#include "FT2Button.generated.h"

class UStaticMeshComponent;

UCLASS()
class FNTASTIC_TASK2_API AFT2Button : public AActor
{
    GENERATED_BODY()

public:
    AFT2Button();

    virtual void Activate();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* ButtonMesh;
};
