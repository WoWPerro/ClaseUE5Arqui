// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentHealth = MaxHealth; //Aquí en el constructor inicializamos la vida
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::TakeDamage(float damageAmount)
{
	if (CurrentHealth <= 0.0f)
	{
		return; // Ya está muerto
	}

	CurrentHealth -= damageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Se ha recibido %f de daño. Vida restante: %f"), damageAmount, CurrentHealth);

	if (CurrentHealth <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("El actor ha muerto."));
	}
}
