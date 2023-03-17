// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectB.generated.h"

/**
 * 
 */
UCLASS()
class NEVERMORE_API UObjectB : public UObject
{
	GENERATED_BODY()

public:

	FVector Vector;
	FQuat Quat;
	FRotator Rotator;
	FTransform Transform;
};
