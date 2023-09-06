#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
UCLASS()
class SLASH_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void MoveForward(float value);
	void MoveRightOrLeft(float value);
	void Turn(float value);
	void LookUp(float value);
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _springComponent;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* _cameraView;
};
