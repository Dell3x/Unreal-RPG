// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Bird.generated.h"

class USkeletalMeshComponent;
class UCapsuleComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class SLASH_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* _birdMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* _moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* _lookAction;

	
	virtual void BeginPlay() override;
	void Move(const FInputActionValue& value);
	void LookAround(const FInputActionValue& Value);

	
private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* _capsuleComponent;
	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* _skeletalMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _springComponent;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* _cameraView;
	
};