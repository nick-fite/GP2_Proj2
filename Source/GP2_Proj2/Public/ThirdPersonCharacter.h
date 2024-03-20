// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
UCLASS()
class GP2_PROJ2_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UFUNCTION() void Move(const FInputActionValue& InputValue);
	UFUNCTION() void Look(const FInputActionValue& InputValue);
	UFUNCTION() void PlayerJump();
	UFUNCTION() void PlayerPunch();
	UFUNCTION() FVector GetMoveForwardDir() const;
	UFUNCTION() FVector GetMoveRightDir() const;

	//Camera
	UPROPERTY(VisibleAnywhere, Category="View") USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category="View") UCameraComponent* ViewCamera;
	UPROPERTY(VisibleAnywhere, Category="Anim") UAnimInstance* AnimInstance;
	
	//Input
	UPROPERTY(EditAnywhere, Category = "Input") UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere, category="Input") UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, category="Input") UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, category="Input") UInputAction* LookAction;
	UPROPERTY(EditAnywhere, category="Input") UInputAction* PunchAction;
	UPROPERTY(EditAnywhere, Category = "Input") float LookSensitivity {0.5f};

	UPROPERTY(EditAnywhere, Category = "Action AnimMontages") UAnimMontage* JumpMontage;
	UPROPERTY(EditAnywhere, Category = "Action AnimMontages") UAnimMontage* PunchMontage;
public:

};
