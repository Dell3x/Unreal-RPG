#include "Slash/Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

ABird::ABird()
{
	PrimaryActorTick.bCanEverTick = true;

	_capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(_capsule);

	_skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	_skeletalMesh->SetupAttachment(GetRootComponent());
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

void ABird::BeginPlay()
{
	Super::BeginPlay();
}

void ABird::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);
}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MovingForward"), this, &ABird::MoveForward);

}

