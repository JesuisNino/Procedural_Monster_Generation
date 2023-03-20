// Fill out your copyright notice in the Description page of Project Settings.


#include "BreedChildMonster.h"

TArray<USkeletalMesh*> UBreedChildMonster::GetChildMeshesArray(const TArray<USkeletalMesh*>& ParentMeshesArray, UDataTable* TagDataTable)
{
	TArray<USkeletalMesh*> ChildMeshesArray;

	TMap<USkeletalMesh*, int32> ParentMeshWithRateMap;

	TArray<FStruct_MasterTags*> TagDataArray;
	TagDataTable->GetAllRows<FStruct_MasterTags>("", TagDataArray);

	for (int32 i = 0; i < ParentMeshesArray.Num(); i++)
	{
		//if (ParentMeshesArray[i] == TagDataArray)
	}

	return ChildMeshesArray;
}