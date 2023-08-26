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

	
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void Move(const FInputActionValue& value);

	
private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* _capsule;
	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* _skeletalMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _springComponent;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* _cameraView;
	
};