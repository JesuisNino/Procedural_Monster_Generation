// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct_BodyPieceImportance.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BreedChildMonster.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UBreedChildMonster : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Breed Child Monster")
	static TMap<FName, USkeletalMesh*> GetChildMeshesArray(
		const TMap<USkeletalMesh*, int32>& RatedMeshMap,
		const TMap<FName, USkeletalMesh*>& LocatedMeshMap,
		const TMap<FName, EImportanceName>& BodyPieceImportanceMap
	);
};