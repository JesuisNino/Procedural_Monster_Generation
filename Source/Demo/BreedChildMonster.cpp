// Fill out your copyright notice in the Description page of Project Settings.


#include "BreedChildMonster.h"

TArray<FChildrenMap>  UBreedChildMonster::CrossoverBreed(
	const TMap<USkeletalMesh*, int32>& RatedMeshMap,
    const TMap<USkeletalMesh*, FName>& LocatedMeshMap,
	const int32 ChildrenNum
)
{
	TArray<FChildrenMap> ChildrenArray;
    TMap<FName, TArray<USkeletalMesh*>> IntegratedLocatedMeshes;

	for (int32 i = 0; i < ChildrenNum; i++) 
	{
        FChildrenMap ChildMap;
        TMap<FName, int32> TotalRateForLocation;

        for (const auto& Location : LocatedMeshMap)
        {
            FName LocationName = Location.Value;
            int32 RatedMeshValue = RatedMeshMap.FindRef(Location.Key);
            
            TotalRateForLocation.FindOrAdd(LocationName) += RatedMeshValue;
            IntegratedLocatedMeshes.FindOrAdd(LocationName).Add(Location.Key);
        }
        
        for (const auto& Location : TotalRateForLocation) 
        {
            FName LocationName = Location.Key;

            // Generate a random number between 1 and TotalRate (inclusive)
            int32 RandomRate = FMath::RandRange(1, Location.Value); 
            USkeletalMesh* SelectedMesh = nullptr;

            for (const auto& RatedMesh : RatedMeshMap)
            {
                int32 CurrentRate = RatedMesh.Value;
                if (RandomRate <= CurrentRate)
                {
                    SelectedMesh = IntegratedLocatedMeshes.FindRef(LocationName)[0];
                    break;
                }
                else 
                {
                    SelectedMesh = IntegratedLocatedMeshes.FindRef(LocationName).Last();
                }
            }

            // Add the selected mesh to the child map
            ChildMap.MeshMap.Add(Location.Key, SelectedMesh);
        }
        
        // Add the child map to the ChildrenArray
        ChildrenArray.Add(ChildMap);

	}
	
	return ChildrenArray;
}

TArray<FChildrenMap> UBreedChildMonster::MutationBreed(const TArray<FChildrenMap>& CrossoveredChildren, const TArray<FChildrenMap>& AvailableLocatedMeshes, const TMap<FName, EImportanceName>& BodyPieceImportanceMap)
{
	return TArray<FChildrenMap>();
}
