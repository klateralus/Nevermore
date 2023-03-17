// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/Instance/MannyAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"


UMannyAnimInstance::UMannyAnimInstance()
    : Super()
    //, AnimInstanceProxy(this)
{
}

void UMannyAnimInstance::PostInitProperties()
{
    Super::PostInitProperties();
}

void UMannyAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    
    const ACharacter* owningCharacter = Cast<ACharacter>(GetOwningActor());
    if (IsValid(owningCharacter))
    {
        MovementComponent = owningCharacter->GetCharacterMovement();
    }
}

void UMannyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (IsValid(MovementComponent))
    {        
        bIsFalling = MovementComponent->IsFalling();
        Velocity = MovementComponent->Velocity;
        Acceleration = MovementComponent->GetCurrentAcceleration();
    }
}

FAnimInstanceProxy* UMannyAnimInstance::CreateAnimInstanceProxy()
{
    return new FMannyAnimInstanceProxy(this);
    // return &AnimInstanceProxy;
}

void UMannyAnimInstance::DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy)
{
    Super::DestroyAnimInstanceProxy(InProxy);
}

const FMannyAnimInstanceProxy& UMannyAnimInstance::GetMannyAnimInstanceProxy() const
{
    return GetProxyOnAnyThread<FMannyAnimInstanceProxy>();
}

bool UMannyAnimInstance::ShouldMove() const
{
    const FMannyAnimInstanceProxy& proxy = GetProxyOnAnyThread<FMannyAnimInstanceProxy>();
    return proxy.ShouldMove();
}

float UMannyAnimInstance::GetGroundSpeed() const
{
    const FMannyAnimInstanceProxy& proxy = GetProxyOnAnyThread<FMannyAnimInstanceProxy>();
    return proxy.GetGroundSpeed();
}

bool UMannyAnimInstance::HasJumped() const
{
    const FMannyAnimInstanceProxy& proxy = GetProxyOnAnyThread<FMannyAnimInstanceProxy>();
    return proxy.HasJumped();
}

bool UMannyAnimInstance::IsNotFalling() const
{
    const FMannyAnimInstanceProxy& proxy = GetProxyOnAnyThread<FMannyAnimInstanceProxy>();
    return !proxy.bIsFalling;
}
