// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class BATSTRIKE_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyPlayer();

	// overrides
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** player move forward control */
	UFUNCTION(BlueprintCallable, Category = PlayerControl)
	void MoveForward(float Val);

	UFUNCTION(BlueprintCallable, Category = PlayerControl)
	void MoveRight(float Val);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	UCameraComponent* PlayerCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	USpringArmComponent* CameraBoom;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
