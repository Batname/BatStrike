// Fill out your copyright notice in the Description page of Project Settings.

#include "BatStrike.h"
#include "MyPlayer.h"


// Sets default values
AMyPlayer::AMyPlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// add player camera and camera boom
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	// Attach camera
	CameraBoom->SetupAttachment(RootComponent);
	PlayerCamera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind input to payer from project setting editor
	InputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
}

void AMyPlayer::MoveForward(float Val)
{
	if (Val != 0.0f)
	{
		FVector Forvard(1, 0, 0);
		AddMovementInput(Forvard, Val);
	}
}

void AMyPlayer::MoveRight(float Val)
{
	FVector Right(0, 1, 0);
	AddMovementInput(Right, Val);
}