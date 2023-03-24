// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Engine/DataTable.h"
#include "Struct_BodyPieceImportance.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EImportanceNames : uint8
{
    MUST,
    POSSIBLE,
    NOT
};

USTRUCT(BlueprintType)
struct FStruct_BodyPieceImportances : public FTableRowBase
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPieceImportance", meta = (ExposeOnSpawn))
        EImportanceNames ImportanceName;
};

UCLASS()
class DEMO_API UStruct_BodyPieceImportance : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};
