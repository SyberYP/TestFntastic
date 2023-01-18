#pragma once

#include "FT2CoreTypes.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class USoundCue;
class USoundBase;

USTRUCT(BlueprintType)
struct FEffectsData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem* SpawnFX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    USoundBase* SpawnSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem* FinishFX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    USoundBase* FinishSound;
};