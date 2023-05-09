// Fill out your copyright notice in the Description page of Project Settings.


#include "BreedChildMonster.h"

TArray<FChildrenMap>  UBreedChildMonster::CrossoverBreed(
	const TMap<USkeletalMesh*, int32>& RatedParentMeshMap,
    const TMap<USkeletalMesh*, FName>& LocatedParentMeshMap,
	const int32 ChildrenNum
)
{
	TArray<FChildrenMap> ChildrenArray;
    TMap<FName, TArray<USkeletalMesh*>> IntegratedLocatedParentMeshes = IntegrateMeshLocation(LocatedParentMeshMap);

	for (int32 i = 0; i < ChildrenNum; i++) 
	{

        FChildrenMap ChildMap;
        TMap<FName, int32> TotalRateForLocation;

        for (const auto& Location : LocatedParentMeshMap)
        {
            
            FName LocationName = Location.Value;
            int32 MeshRate = RatedParentMeshMap.FindRef(Location.Key);
            
            TotalRateForLocation.FindOrAdd(LocationName) += MeshRate;
           
        }
        
        for (const auto& Location : TotalRateForLocation) 
        {

            FName LocationName = Location.Key;

            // Generate a random number between 1 and TotalRate (inclusive)
            int32 RandomRate = FMath::RandRange(1, Location.Value); 
            USkeletalMesh* SelectedMesh = nullptr;

            for (const auto& RatedMesh : RatedParentMeshMap)
            {
                int32 CurrentRate = RatedMesh.Value;
                if (RandomRate <= CurrentRate)
                {
                    SelectedMesh = IntegratedLocatedParentMeshes.FindRef(LocationName)[0];
                    break;
                }
                else 
                {
                    SelectedMesh = IntegratedLocatedParentMeshes.FindRef(LocationName).Last();
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

TArray<FChildrenMap> UBreedChildMonster::MutationBreed(
    const TArray<FChildrenMap>& CrossoveredChildren,
    const TMap<USkeletalMesh*, FName>& LocatedParentMeshMap,
    const TMap<USkeletalMesh*, int32>& RatedAllMeshMap,
    const TMap<USkeletalMesh*, FName>& LocatedAllMeshMap,
    const TMap<FName, EImportanceName>& BodyPieceImportanceMap,
    const float Coefficient
)
{
    TArray<FChildrenMap> ChildrenArray;

    TMap<FName, TArray<USkeletalMesh*>> IntegratedLocatedParentMeshes = IntegrateMeshLocation(LocatedParentMeshMap);
    TMap<FName, TArray<USkeletalMesh*>> IntegratedLocatedAllMeshes = IntegrateMeshLocation(LocatedAllMeshMap);
    TMap<USkeletalMesh*, float> RatedMutationMeshMap;

    for (const auto& Child : CrossoveredChildren) 
    {
        FChildrenMap ChildMap;
        TMap<FName, float> TotalRateForLocation;

        for (const auto& Location : LocatedAllMeshMap)
        {
            FName LocationName = Location.Value;

            float MeshRate = RatedAllMeshMap.FindRef(Location.Key);

            if (Coefficient >= 1) {
                TotalRateForLocation.FindOrAdd(LocationName) += MeshRate;
                RatedMutationMeshMap.FindOrAdd(Location.Key) = MeshRate;
            }
            else if (IntegratedLocatedParentMeshes.FindRef(LocationName).Contains(Location.Key))
            {
                TotalRateForLocation.FindOrAdd(LocationName) += MeshRate * (1 - Coefficient) / 2;
                RatedMutationMeshMap.FindOrAdd(Location.Key) = (1 - Coefficient) / 2;
            }
            else
            {
                TotalRateForLocation.FindOrAdd(LocationName) += MeshRate * Coefficient / (IntegratedLocatedAllMeshes.FindRef(LocationName).Num() - 2);
                RatedMutationMeshMap.FindOrAdd(Location.Key) = Coefficient / (IntegratedLocatedAllMeshes.FindRef(LocationName).Num() - 2);
            }
        
        }

        for (const auto& ChildBodyPiece : Child.MeshMap)
        {

            FName LocationName = ChildBodyPiece.Key;

            // Generate a random number between 0 and TotalRate (inclusive)
            float RandomRate = FMath::RandRange(0.0f, TotalRateForLocation.FindRef(LocationName));
            float CurrentRate = 0;
            USkeletalMesh* SelectedMesh = nullptr;

            TArray<USkeletalMesh*> TempArray = IntegratedLocatedAllMeshes.FindRef(LocationName);
           
            TempArray.Sort([&RatedMutationMeshMap](const USkeletalMesh& MeshA, const USkeletalMesh& MeshB) {
                float AValue = RatedMutationMeshMap.FindRef(&MeshA);
                float BValue = RatedMutationMeshMap.FindRef(&MeshB);
                return AValue > BValue;
                });

            // Roulette Wheel Selection Implementation
            for (const auto& AvailableMesh : TempArray)
            {
                CurrentRate += RatedMutationMeshMap.FindRef(AvailableMesh);
                if (RandomRate <= CurrentRate)
                {
                    SelectedMesh = AvailableMesh;
                    break;
                }
            }

            // Add the selected mesh to the child map
            ChildMap.MeshMap.Add(ChildBodyPiece.Key, SelectedMesh);

        }

        // Add the child map to the ChildrenArray
        ChildrenArray.Add(ChildMap);
    }

    

	return ChildrenArray;
}

TMap<FName, TArray<USkeletalMesh*>> UBreedChildMonster::IntegrateMeshLocation(const TMap<USkeletalMesh*, FName>& LocatedMeshMap)
{
    TMap<FName, TArray<USkeletalMesh*>> IntegratedLocatedMeshes;

    for (const auto& Location : LocatedMeshMap)
    {
        IntegratedLocatedMeshes.FindOrAdd(Location.Value).Add(Location.Key);
    }

    return IntegratedLocatedMeshes;
}

FVector UBreedChildMonster::MorphBreed(
    const FVector& ParentA,
    const FVector& ParentB,
    const float Coefficient
) {
    // Calculate the range for ParentA and ParentB
    FVector MinParentA = ParentA * (1.0f - Coefficient);
    FVector MaxParentA = ParentA * (1.0f + Coefficient);
    FVector MinParentB = ParentB * (1.0f - Coefficient);
    FVector MaxParentB = ParentB * (1.0f + Coefficient);

    // Randomly generate child vector components within the range of ParentA and ParentB
    FVector ChildVectorA, ChildVectorB;
    ChildVectorA.X = FMath::FRandRange(MinParentA.X, MaxParentA.X);
    ChildVectorA.Y = FMath::FRandRange(MinParentA.Y, MaxParentA.Y);
    ChildVectorA.Z = FMath::FRandRange(MinParentA.Z, MaxParentA.Z);
    ChildVectorB.X = FMath::FRandRange(MinParentB.X, MaxParentB.X);
    ChildVectorB.Y = FMath::FRandRange(MinParentB.Y, MaxParentB.Y);
    ChildVectorB.Z = FMath::FRandRange(MinParentB.Z, MaxParentB.Z);

    // Randomly choose one of the generated child vectors
    FVector ChildVector = FMath::FRand() < 0.5f ? ChildVectorA : ChildVectorB;

    return ChildVector;
}
