#include "NewItem.h"

ANewItem::ANewItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	_newItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = _newItemMesh;	
}

void ANewItem::BeginPlay()
{
	Super::BeginPlay();
	

}

float ANewItem::TransformedSin()
  {
	return  MovementAmplitude * FMath::Sin(RunningTime * MovementMultiplayer);
}

float ANewItem::TransformedCos()
{
	return  MovementAmplitude * FMath::Cos(RunningTime * MovementMultiplayer);
}

void ANewItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RunningTime += DeltaTime;

	AddActorWorldRotation(FRotator(0.f, 45.f * DeltaTime,0.f));
}
