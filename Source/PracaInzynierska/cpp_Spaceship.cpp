// Fill out your copyright notice in the Description page of Project Settings.


#include "cpp_Spaceship.h"

// Sets default values
Acpp_Spaceship::Acpp_Spaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		this->forwardGears = 5;
		this->backwardGears = 2;
		this->actualGear = 0;
		this->maxSpeed = 100;
		this->reverseThrusterPower = 10;
		this->forwardThrusterPower = 50;
		this->rotationThrusterPower = 25;
		this->shipMass = 1;
		this->velocityVector = { 0,0,0 };
		this->energyVector = { 0,0,0 };

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

void Acpp_Spaceship::gearUp()
{
	if (this->actualGear < this->forwardGears)this->actualGear++;
}

void Acpp_Spaceship::gearDown()
{
	if (this->actualGear > 0 || this->actualGear > (-1*this->backwardGears))this->actualGear--;
}

void Acpp_Spaceship::stop()
{
	this->actualGear = 0;
}

void Acpp_Spaceship::addEnergy(UPARAM(ref) float deltaTime)
{
	FRotator actorRotation = this->GetActorRotation();
	FVector deltaEnergyVector = {};

	if (this->actualGear == 0)return;
	if (this->actualGear > 0)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!1"));
		deltaEnergyVector = { this->forwardThrusterPower * deltaTime * ((float)this->actualGear/ (float)this->forwardGears),0,0 };
	}
	else if (this->actualGear < 0)
	{
		deltaEnergyVector = { this->forwardThrusterPower * deltaTime * ((float)this->actualGear / (float)this->backwardGears),0,0 };
	}

	deltaEnergyVector = actorRotation.RotateVector(deltaEnergyVector);
	this->energyVector += deltaEnergyVector;
}

void Acpp_Spaceship::calculateVelocityVector()
{
	FVector deltaVelocity = (this->energyVector * 2) / this->shipMass;
	deltaVelocity.X = sqrt(deltaVelocity.X);
	deltaVelocity.Z = sqrt(deltaVelocity.Z);
	this->velocityVector = deltaVelocity;
}
