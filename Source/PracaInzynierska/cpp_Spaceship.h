// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "cpp_Spaceship.generated.h"


UCLASS(Blueprintable)
class PRACAINZYNIERSKA_API Acpp_Spaceship : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Acpp_Spaceship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		int actualGear;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		int forwardGears;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		int backwardGears;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float maxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float maxEnergyVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float reverseThrusterPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float forwardThrusterPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float rotationThrusterPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float shipMass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float dragFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float fluidDensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		FVector energyVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		FVector velocityVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		FVector dragVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Variables")
		float dragForce;
	

	


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void gearUp();
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void gearDown();
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void stop();
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void addEnergy(UPARAM(ref) float deltaTime, UPARAM(ref) float actorRotation);
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void calculateVelocityVector(UPARAM(ref) float actorRotation);
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void calculateDragForce(UPARAM(ref) float velocity);
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		void calculateDragVector(UPARAM(ref) float deltaTime);
	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
		int determineTurnDirection(UPARAM(ref) float actualAngle, UPARAM(ref) float targetAngle);
};
