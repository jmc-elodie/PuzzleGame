// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority())
	{
		const auto CurrentLoc = GetActorLocation();
		const auto DistTraveled = (WorldStartLocation - CurrentLoc).Size();
		const auto TotalDistance = (WorldStartLocation - WorldTargetLocation).Size();

		if (DistTraveled > TotalDistance)
		{
			const FVector Swap = WorldStartLocation;
			WorldStartLocation = WorldTargetLocation;
			WorldTargetLocation = Swap;
		}

		const auto DestDirection = (WorldTargetLocation - WorldStartLocation).GetSafeNormal();
		SetActorLocation(CurrentLoc + DestDirection * Speed * DeltaSeconds);
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	WorldStartLocation = GetActorLocation();
	WorldTargetLocation = ActorToWorld().TransformPosition(TargetLocation);
	
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}
