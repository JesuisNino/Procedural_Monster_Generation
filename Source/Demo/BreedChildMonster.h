// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
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
	static TArray<USkeletalMesh*> GetChildMeshesArray(const TArray<USkeletalMesh*>& ParentMeshesArray, UDataTable* TagDataTable);
	
};