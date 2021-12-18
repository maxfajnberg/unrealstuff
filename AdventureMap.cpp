// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureMap.h"
#include "HexTile.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AAdventureMap::AAdventureMap()
{
}

// Called when the game starts or when spawned
void AAdventureMap::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(BaseTileClass)) { MakeGrid(); }

	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	int32 RandomSpawn = FMath::RandRange(0, GridSize * GridSize);
	AHexTile* SpawnHex = Grid[RandomSpawn];
	FVector SpawnLocation = SpawnHex->GetActorLocation();
	Player->SetActorLocation(SpawnLocation + FVector(0, 0, 80));
}

void AAdventureMap::MakeGrid() 
{
	FVector SpawnLocation = FVector();
	float HexWidth = sqrt(3) * TileSize;
	int QOffset = 0;

	for (int r = 1; r <= GridSize; r++) 
	{
		float XOffset = 0.f;
		if (r % 2 != 0)	{ if (r > 1) { QOffset--; }	}
		else { XOffset = HexWidth / 2; }

		for (int q = 1; q <= GridSize; q++)
		{
			SpawnLocation.X = XOffset + (HexWidth * q);
			SpawnLocation.Y = TileSize * 1.5f * r;
			SpawnLocation.Z = 0.f;

			FTransform SpawnTransform = FTransform(SpawnLocation);
			AHexTile* Tile = GetWorld()->SpawnActor<AHexTile>(BaseTileClass, SpawnTransform);

			Tile->Q = q - 1 + QOffset;
			Tile->R = r - 1;

			Grid.Add(Tile);
		}
	}

	// debug
	for (auto& tile : Grid)
	{
		tile->Index = GridIndex(tile->Q, tile->R);
	}
}

// Every Hex Tile's index within the Grid Array can be derived from its Q and R coordinates
int32 AAdventureMap::GridIndex(int32 qAxial, int32 row) 
{	
	/*	
	*	The Q axis is (i.e. columns are) oriented diagonally.
	*	The Grid has a rough square shape, hence the Q coordinates are offset by -1 every other row.
	*/
	int32 column = qAxial + FMath::FloorToInt(row/2); 
	return (row * GridSize) + column;
}