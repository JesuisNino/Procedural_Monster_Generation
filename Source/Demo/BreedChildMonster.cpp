// Fill out your copyright notice in the Description page of Project Settings.


#include "BreedChildMonster.h"

TArray<USkeletalMesh*>  UBreedChildMonster::GetChildMeshesArray(const TArray<USkeletalMesh*>& ParentMeshesArray, UDataTable* TagDataTable)
{
	TArray<USkeletalMesh*> ChildMeshesArray;

	TMap<USkeletalMesh*, int32> ParentMeshWithRateMap;

	TArray<USkeletalMesh*> SkeletalMeshesArray;

	// Iterate through each FStruct_MasterTags in the TagDataArray
	//for (int32 i = 0; i < ParentMeshesArray.Num(); i++)
	//{

	//}

	return ChildMeshesArray;
}