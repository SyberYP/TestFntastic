// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FT2Pawn.generated.h"

class UCameraComponent;

UCLASS()
class FNTASTIC_TASK2_API AFT2Pawn : public APawn
{
    GENERATED_BODY()

public:
    AFT2Pawn();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

private:
    void LeftMouseClick();

    void TraceChannelByClick();
};
