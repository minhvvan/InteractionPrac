// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractDoor.h"
#include "InteractBroom.generated.h"


/**
 * 
 */
UCLASS()
class INTERACTIONPRAC_API AInteractBroom : public AInteractDoor
{
	GENERATED_BODY()
	
	virtual void Tick(float DeltaSeconds) override;

public:
	AInteractBroom();

	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	UPROPERTY()
	class AInteractionPracCharacter* Player;
};
