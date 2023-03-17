// Fill out your copyright notice in the Description page of Project Settings.


#include "PerformanceTest.h"


// Sets default values
APerformanceTest::APerformanceTest()
	: Super()
{
	ObjectA = NewObject<UObjectA>(this);
	ObjectB = NewObject<UObjectB>(this);

 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

APerformanceTest::APerformanceTest(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	ObjectA = NewObject<UObjectA>(this, FName("ObjectA"));
	ObjectB = NewObject<UObjectB>(this, FName("ObjectB"));

	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APerformanceTest::BeginPlay()
{
	Super::BeginPlay();
	
	EvaluateFunction(std::bind(&APerformanceTest::TestAssignment, this));
	EvaluateFunction(std::bind(&APerformanceTest::TestMemcpy, this));
}

// Called every frame
void APerformanceTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APerformanceTest::TestAssignment()
{
	for (int i = 0; i < 1000000; ++i)
	{
		ObjectB->Vector = ObjectA->Vector;
		ObjectB->Quat = ObjectA->Quat;
		ObjectB->Rotator = ObjectA->Rotator;
		ObjectB->Transform = ObjectA->Transform;
	}
}

void APerformanceTest::TestMemcpy()
{
	for (int i = 0; i < 1000000; ++i)
	{
		memcpy(&(ObjectB->Vector), &(ObjectA->Vector), sizeof(ObjectB->Vector));
		memcpy(&(ObjectB->Quat), &(ObjectA->Quat), sizeof(ObjectB->Quat));
		memcpy(&(ObjectB->Rotator), &(ObjectA->Rotator), sizeof(ObjectB->Rotator));
		memcpy(&(ObjectB->Transform), &(ObjectA->Transform), sizeof(ObjectB->Transform));
	}
}

void APerformanceTest::EvaluateFunction(std::function<void()> func)
{
	const uint64 StartCycles = FPlatformTime::Cycles64();
	func();
	const uint64 EndCycles = FPlatformTime::Cycles64();
	const double ElapsedTimeMilliseconds = FPlatformTime::ToMilliseconds(EndCycles - StartCycles);
	UE_LOG(LogTemp, Log, TEXT("Elapsed time: %f milliseconds"), ElapsedTimeMilliseconds);
}

