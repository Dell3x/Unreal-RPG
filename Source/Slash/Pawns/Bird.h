// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"

class USkeletalMeshComponent;
class UCapsuleComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SLASH_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void MoveForward(float Value);
private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* _capsule;
	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* _skeletalMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _springArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* _cameraComponent;
	
};