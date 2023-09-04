#include "Slash/Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"


ABird::ABird()
{
	PrimaryActorTick.bCanEverTick = true;

	_capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(_capsuleComponent);

	_skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	_skeletalMesh->SetupAttachment(GetRootComponent());

	_springComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_springComponent->SetupAttachment(GetRootComponent());
	_springComponent->TargetArmLength = 300.f;

	_cameraView = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraView"));
	_cameraView->SetupAttachment(_springComponent);

}

void ABird::BeginPlay()
{
	Super::BeginPlay();

	if(APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			subSystem->AddMappingContext(_birdMappingContext, 0);
		}
	} 
}

void ABird::Move(const FInputActionValue& value)
{
	const FVector2d directionValue = value.Get<FVector2d>();
	
	if(Controller)
	{
		FVector forwardVector = GetActorForwardVector();
		FVector rightVector = GetActorRightVector();
		AddMovementInput(forwardVector, directionValue.Y);
		AddMovementInput(rightVector, directionValue.X);
	}
}

void ABird::LookAround(const FInputActionValue& Value)
{
	const FVector2D lookAxisValue = Value.Get<FVector2D>();

	if(GetController())
	{
		AddControllerYawInput(lookAxisValue.X);
		AddControllerPitchInput(lookAxisValue.Y);
	}

}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* enhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInput->BindAction(_moveAction, ETriggerEvent::Triggered, this, &ABird::Move);
		enhancedInput->BindAction(_lookAction, ETriggerEvent::Triggered, this, &ABird::LookAround);
	}

}

