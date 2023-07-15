#include "NewItem.h"

ANewItem::ANewItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANewItem::BeginPlay()
{
	Super::BeginPlay();
}

void ANewItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

