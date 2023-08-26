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

	_capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(_capsule);

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

void ABird::MoveForward(float Value)
{
	
}

void ABird::Move(const FInputActionValue& value)
{
	const float directionValue = value.Get<float>();
	
	if(Controller && directionValue != 0.f)
	{
		FVector forwardVector = GetActorForwardVector();
		AddMovementInput(forwardVector, directionValue);
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
		enhancedInput->BindAction(_moveAction, ETriggerEvent::Triggered, this,&ABird::Move);
	}

}

