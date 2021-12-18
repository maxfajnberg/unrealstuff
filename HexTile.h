// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "HexTile.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class FRAY_API AHexTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default value for this actor's properties
	AHexTile();

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
		float TileSize;
	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* SceneComponent;

	UFUNCTION (BlueprintCallable)
		FVector Corner(int32 i);
	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Runtime")
		TArray<FVector> Corners;
	UFUNCTION ()
		void FillCornersArray();

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Runtime")
		int32 Q;
	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Runtime")
		int32 R;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Runtime")
		int32 Index;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

