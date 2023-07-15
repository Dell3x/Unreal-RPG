#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewItem.generated.h"

UCLASS()
class SLASH_API ANewItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ANewItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
