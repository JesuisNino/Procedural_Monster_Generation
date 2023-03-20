// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BreedChildMonster.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FStruct_MaterialSetup
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Paramater Name"))
		FName ParamaterName;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Slot Index"))
		int32 SlotIndex;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Material Reference"))
		TObjectPtr<UMaterial> MaterialReference;
};

USTRUCT(BlueprintType)
struct FStruct_MorphTargetSetup
{
	GENERATED_BODY()
public:
	/** This Text Will Appear On Customization Section */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Widget Name"))
		FText WidgetName;

	/** Specific Name Of The Morph Target */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Morph Target Name"))
		FName MorphTargetName;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Default Value"))
		float DefaultValue;

	/** It Will Convert The X(Min) and Y(Max) Values To -1,1 Range */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Normalize To Range"))
		FVector2D NormalizeToRange;
};

USTRUCT(BlueprintType)
struct FStruct_ColorSchemeSetup
{
	GENERATED_BODY()
public:
	/** This Text Will Appear On Customization Menu */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Widget Title"))
		FText WidgetTitle;

	/** Available Colors To Select */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Available Colors"))
		TArray<FLinearColor> AvailableColors;

	/** Material Reference To Create Dynamic Instance */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Material Setup"))
		TArray<FStruct_MaterialSetup> MaterialSetup;
};

USTRUCT(BlueprintType)
struct FStruct_AvailableMeshMaster
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Skeletal Mesh"))
		TObjectPtr<USkeletalMesh> SkeletalMesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Item Icon"))
		TObjectPtr<UTexture2D> ItemIcon;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Morph Targets"))
		TArray<FStruct_MorphTargetSetup> MorphTargets;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Color Schemes"))
		TArray<FStruct_ColorSchemeSetup> ColorSchemes;
};


USTRUCT(BlueprintType)
struct FStruct_MasterTags
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Tab Name"))
		FText TabName;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Available Meshes"))
		TArray<FStruct_AvailableMeshMaster> AvailableMeshes;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Rate"))
		int32 Rate;
};


UCLASS()
class DEMO_API UBreedChildMonster : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Breed Child Monster")
	static TArray<USkeletalMesh*> GetChildMeshesArray(const TArray<USkeletalMesh*>& ParentMeshesArray, UDataTable* TagDataTable);
	
};