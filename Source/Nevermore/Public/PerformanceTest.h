// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <functional>
#include "ObjectA.h"
#include "ObjectB.h"
#include "PerformanceTest.generated.h"


UCLASS(BlueprintType, Blueprintable)
class NEVERMORE_API APerformanceTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerformanceTest();

	/** Constructor for AActor that takes an ObjectInitializer for backward compatibility */
	APerformanceTest(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
	UObjectA* ObjectA;

	UPROPERTY()
	UObjectB* ObjectB;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void TestAssignment();
	void TestMemcpy();
	void EvaluateFunction(std::function<void()> func);
};
