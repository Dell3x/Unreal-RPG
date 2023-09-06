#include "Characters/MainCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	_springComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_springComponent->SetupAttachment(GetRootComponent());
	_springComponent->TargetArmLength = 300.f;

	_cameraView = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraView"));
	_cameraView->SetupAttachment(_springComponent);

}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacter::MoveForward(float value)
{
	FVector forwardVector = GetActorForwardVector();
	AddMovementInput(forwardVector, value);
}

void AMainCharacter::MoveRightOrLeft(float value)
{
	FVector rightVector = GetActorRightVector();
	AddMovementInput(rightVector, value);	
}

void AMainCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void AMainCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MovingForwardOrBack"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRightOrLeft"), this, &AMainCharacter::MoveRightOrLeft);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AMainCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AMainCharacter::LookUp);
}

