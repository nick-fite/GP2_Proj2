// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GP2_PROJ2_API UDamageSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere) int AttackTokens{1};

public:
	UFUNCTION(BlueprintCallable)
	bool ReserveAttackToken(int amount);
	UFUNCTION(BlueprintCallable)
	void ReturnAttackToken(int amount);
	UFUNCTION(BlueprintCallable)
	int GetTokenAmount();

};
