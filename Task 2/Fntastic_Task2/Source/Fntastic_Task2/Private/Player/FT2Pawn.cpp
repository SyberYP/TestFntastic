// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/FT2Pawn.h"
#include "Camera/CameraComponent.h"
#include "Gameplay/FT2Button.h"
#include "Player/FT2PlayerController.h"
#include "GameFramework/PlayerController.h"

AFT2Pawn::AFT2Pawn()
{
    AutoPossessPlayer = EAutoReceiveInput::Player0;
    PrimaryActorTick.bCanEverTick = false;
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(GetRootComponent());
}

void AFT2Pawn::BeginPlay()
{
    Super::BeginPlay();
}

void AFT2Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);

    PlayerInputComponent->BindAction("LeftMouseClick", EInputEvent::IE_Pressed, this, &AFT2Pawn::LeftMouseClick);
}

void AFT2Pawn::LeftMouseClick()
{
    TraceChannelByClick();
}

void AFT2Pawn::TraceChannelByClick()
{
    if (!GetWorld()) return;

    FVector Start, End, Direction;

    if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
    {
        PlayerController->DeprojectMousePositionToWorld(Start, Direction);
        End = Start + (Direction * 8000.0f);
    }

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
    if (!HitResult.Actor.IsValid()) return;

    const auto Button = Cast<AFT2Button>(HitResult.Actor.Get());
    if (!Button) return;

    Button->Activate();
}
