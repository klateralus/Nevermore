// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/Proxy/MannyAnimInstanceProxy.h"
#include "Anim/Instance/MannyAnimInstance.h"


FMannyAnimInstanceProxy::FMannyAnimInstanceProxy()
    : Super()
{
}

FMannyAnimInstanceProxy::FMannyAnimInstanceProxy(UAnimInstance* Instance)
    : Super(Instance)
{
    const UMannyAnimInstance* mannyAnimInstance = Cast<UMannyAnimInstance>(Instance);
    if (IsValid(mannyAnimInstance))
    {
        // copy settings
        MinimalSpeed = mannyAnimInstance->MinimalSpeed;
        MinimalVelocityZ = mannyAnimInstance->MinimalVelocityZ;
    }
}

void FMannyAnimInstanceProxy::PreUpdate(UAnimInstance* InAnimInstance, float DeltaSeconds)
{
    Super::PreUpdate(InAnimInstance, DeltaSeconds);

    const UMannyAnimInstance* mannyAnimInstance = Cast<UMannyAnimInstance>(InAnimInstance);
    if (IsValid(mannyAnimInstance))
    {        
        bIsFalling = mannyAnimInstance->bIsFalling;
        Velocity = mannyAnimInstance->Velocity;
        Acceleration = mannyAnimInstance->Acceleration;
    }
}

/*void FMannyAnimInstanceProxy::Update(float DeltaSeconds)
{
    Super::Update(DeltaSeconds);
}*/

bool FMannyAnimInstanceProxy::ShouldMove() const
{
    return (!Acceleration.IsNearlyZero(0.01f)) && (GetGroundSpeed() > MinimalSpeed);
}

float FMannyAnimInstanceProxy::GetGroundSpeed() const
{
    return Velocity.Size2D();
}

bool FMannyAnimInstanceProxy::HasJumped() const
{
    return bIsFalling && (Velocity.Z > MinimalVelocityZ);
}
