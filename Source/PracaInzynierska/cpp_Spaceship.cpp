// Fill out your copyright notice in the Description page of Project Settings.


#include "cpp_Spaceship.h"

// Sets default values
Acpp_Spaceship::Acpp_Spaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Acpp_Spaceship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acpp_Spaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Acpp_Spaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

