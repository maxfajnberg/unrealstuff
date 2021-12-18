// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AdventureMap.generated.h"

class AHexTile;

UCLASS()
class FRAY_API AAdventureMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAdventureMap();

	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Config")
		TSubclassOf<AHexTile> BaseTileClass;
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Config")
		int32 GridSize = 100; // squared is the number of Tiles
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Config")
		int32 TileSize = 100;

	UPROPERTY (VisibleInstanceOnly, BlueprintReadWrite, Category = "MapData")
		TArray<AHexTile*> Grid;
	UFUNCTION (BlueprintCallable)
		int32 GridIndex(int32 q, int32 r);
	//UFUNCTION (BlueprintCallable)
	//	int32 Q(int32 arrayIndex);
	//UFUNCTION (BlueprintCallable)
	//	int32 R(int32 arrayIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION (BlueprintCallable)
		void MakeGrid();
};