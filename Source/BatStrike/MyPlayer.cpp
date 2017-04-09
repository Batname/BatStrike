// Fill out your copyright notice in the Description page of Project Settings.

#include "BatStrike.h"
#include "MyPlayer.h"
#include "Weapon.h"


// Sets default values
AMyPlayer::AMyPlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Camera Player object and add test for blueprints
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));

	// Create Camera boom
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
	InputComponent->BindAction("StartFire", IE_Pressed, this, &AMyPlayer::OnFire);
	InputComponent->BindAction("StopFire", IE_Released, this, &AMyPlayer::OnStopFire);

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

void AMyPlayer::OnFire()
{
	UE_LOG(LogClass, Warning, TEXT("StartFire"));
}

void AMyPlayer::OnStopFire()
{
	UE_LOG(LogClass, Warning, TEXT("OnStopFire"));
}