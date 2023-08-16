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

	UFUNCTION(BlueprintPure)
	float TransformedSin();
	
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T First, T Second);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
	UPROPERTY(EditAnywhere)
	float MovementAmplitude = 0.25f;
	UPROPERTY(EditAnywhere)
	float MovementMultiplayer = 5.f;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* _newItemMesh;
};


template <typename T>
T ANewItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
