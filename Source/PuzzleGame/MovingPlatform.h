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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Config)
	float Speed;
};
