// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEGAME_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();

	void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category=Config)
	float Speed = 20.0f;

	UPROPERTY(EditAnywhere, Category = Config, meta=(MakeEditWidget=true))
	FVector TargetLocation;

protected:

	FVector WorldStartLocation;

	FVector WorldTargetLocation;

	void BeginPlay() override;
};
