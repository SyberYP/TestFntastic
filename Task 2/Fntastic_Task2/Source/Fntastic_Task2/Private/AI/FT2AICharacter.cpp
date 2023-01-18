// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/FT2AICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

AFT2AICharacter::AFT2AICharacter()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AFT2AICharacter::ActivateStart()
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), //
        EffectsData.SpawnFX,                                   //
        GetActorLocation(),                                    //
        GetActorRotation());

    UGameplayStatics::PlaySoundAtLocation(GetWorld(), EffectsData.SpawnSound, GetActorLocation());
}

void AFT2AICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AFT2AICharacter::ActivateFinished()
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), //
        EffectsData.FinishFX,                                    //
        GetActorLocation(),                           //
        GetActorRotation());

    UGameplayStatics::PlaySoundAtLocation(GetWorld(), EffectsData.FinishSound, GetActorLocation());
}
