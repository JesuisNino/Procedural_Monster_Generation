// Fill out your copyright notice in the Description page of Project Settings.


#include "BreedChildMonster.h"

TMap<FName, USkeletalMesh*>  UBreedChildMonster::GetChildMeshesArray(
	const TMap<USkeletalMesh*, int32>& RatedMeshMap,
	const TMap<FName, USkeletalMesh*>& LocatedMeshMap,
	const TMap<FName, EImportanceName>& BodyPieceImportanceMap
)
{
	TMap<FName, USkeletalMesh*> ChildMeshMap;

	TMap<USkeletalMesh*, int32> ParentMeshWithRateMap;

	TArray<USkeletalMesh*> SkeletalMeshesArray;

	// Iterate through each FStruct_MasterTags in the TagDataArray
	//for (int32 i = 0; i < ParentMeshesArray.Num(); i++)
	//{

	//}

	return ChildMeshMap;
}