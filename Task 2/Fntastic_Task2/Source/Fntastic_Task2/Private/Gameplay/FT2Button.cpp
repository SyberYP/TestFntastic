// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/FT2Button.h"
#include "Components/StaticMeshComponent.h"

AFT2Button::AFT2Button()
{
    PrimaryActorTick.bCanEverTick = false;

    ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>("ButtonMesh");
}

void AFT2Button::BeginPlay()
{
    Super::BeginPlay();
}

void AFT2Button::Activate()
{
    UE_LOG(LogTemp, Display, TEXT("Activate in parent class"));
}
