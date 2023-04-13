// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractBroom.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "InteractionPracCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AInteractBroom::AInteractBroom()
{
}

void AInteractBroom::Tick(float DeltaSeconds)
{
	if (GetWorld()->GetPlayerControllerIterator()->Get()->WasInputKeyJustPressed(EKeys::E))
	{
		if (IsOverlapped)
		{
			if (Player)
			{
				UE_LOG(LogTemp, Warning, TEXT("Broom Ride"));
				FName WeaponSocket(TEXT("ride"));

				AttachToComponent(Player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
			
				Mesh->SetCollisionProfileName(TEXT("Ignore"));
				Widget->SetActive(false);
				Widget->SetVisibility(false);

				//GetOwner()
				auto Character = Cast<AInteractionPracCharacter>(GetAttachParentActor());
				Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
			}
		}
	}
}

void AInteractBroom::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	Player = Cast<AInteractionPracCharacter>(OtherActor);
	if (Player)
	{
		Player->IsAttach = true;
	}
}

void AInteractBroom::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);

	Player = nullptr;
}
