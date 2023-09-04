#include "Characters/MainCharacter.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

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

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MovingForwardOrBack"), this, &AMainCharacter::MoveForward);
}

