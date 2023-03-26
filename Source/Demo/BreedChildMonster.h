// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct_BodyPieceImportance.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BreedChildMonster.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FChildrenMap
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, USkeletalMesh*> MeshMap;
};

UCLASS()
class DEMO_API UBreedChildMonster : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Breed Child Monster")
	static TArray<FChildrenMap> CrossoverBreed(
		const TMap<USkeletalMesh*, int32>& RatedParentMeshMap,
		const TMap<USkeletalMesh*, FName>& LocatedParentMeshMap,
		const int32 ChildrenNum
	);

	UFUNCTION(BlueprintCallable, Category = "Breed Child Monster")
	static TArray<FChildrenMap> MutationBreed(
		const TArray<FChildrenMap>& CrossoveredChildren,
		const TMap<USkeletalMesh*, FName>& LocatedParentMeshMap,
		const TMap<USkeletalMesh*, int32>& RatedAllMeshMap,
		const TMap<USkeletalMesh*, FName>& LocatedAllMeshMap,
		const TMap<FName, EImportanceName>& BodyPieceImportanceMap,
		const float Coefficient
	);

protected:
	static TMap<FName, TArray<USkeletalMesh*>> IntegrateMeshLocation(
		const TMap<USkeletalMesh*, FName>& LocatedMeshMap
	);
};