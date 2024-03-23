// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/DamageSystem.h"

// Sets default values for this component's properties
UDamageSystem::UDamageSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamageSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDamageSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UDamageSystem::ReserveAttackToken(int amount)
{
	if(AttackTokens > 0)
	{
		AttackTokens -= amount;
		return true;
	}
	return false;
}

void UDamageSystem::ReturnAttackToken(int amount)
{
	AttackTokens += amount;
}

int UDamageSystem::GetTokenAmount()
{
	return AttackTokens;
}
