#include "Characters/MainCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	
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
	const FRotator controllerRotation = GetControlRotation();
	const FRotator yawRotation(0.f, controllerRotation.Yaw, 0.f);
	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	
	AddMovementInput(direction, value);
}

void AMainCharacter::MoveRightOrLeft(float value)
{
	const FRotator controllerRotation = GetControlRotation();
	const FRotator yawRotation(0.f, controllerRotation.Yaw, 0.f);
	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	
	AddMovementInput(direction, value);
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

