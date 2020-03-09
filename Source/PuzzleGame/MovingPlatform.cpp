// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	Speed = 5.0f;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority())
	{
		auto CurrentLoc = GetActorLocation();
		CurrentLoc += FVector(Speed * DeltaSeconds, 0.f, 0.f);
		SetActorLocation(CurrentLoc);
	}
}
