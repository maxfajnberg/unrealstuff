// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTile.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AHexTile::AHexTile()
{
	TileSize = 100.f;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	this->FillCornersArray();
}

void AHexTile::BeginPlay()
{
	Super::BeginPlay();
}

FVector AHexTile::Corner(int32 i)
{
	FVector TileCenter = this->GetActorTransform().GetLocation();

	int32 Angle_Deg = 60 * i - 30;
	float Angle_Rad = UKismetMathLibrary::GetPI()/180 * Angle_Deg;
	float X = TileCenter.X + TileSize * cos(Angle_Rad);
	float Y = TileCenter.Y + TileSize * sin(Angle_Rad);

	return FVector(X, Y, 0.f);
}
void AHexTile::FillCornersArray() 
{
	for (int32 i = 0 ; i < 6; i++)
	{
		Corners.Emplace(Corner(i + 1));
	}
}

