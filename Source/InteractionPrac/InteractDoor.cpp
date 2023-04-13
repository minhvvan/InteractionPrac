// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"

// Sets default values
AInteractDoor::AInteractDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IsOverlapped = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Widget = CreateDefaultSubobject<UWidgetComponent >(TEXT("Widget"));

	if (IsValid(Trigger))
	{
		Trigger->SetBoxExtent(FVector(100.f, 100.f, 150.f));
	}

	SetRootComponent(Mesh);
	Trigger->SetupAttachment(RootComponent);
	Widget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AInteractDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractDoor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AInteractDoor::OnOverlapBegin);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AInteractDoor::OnOverlapEnd);
	Widget->SetVisibility(false);
}

void AInteractDoor::Tick(float DeltaSeconds)
{
	if (GetWorld()->GetPlayerControllerIterator()->Get()->WasInputKeyJustPressed(EKeys::E))
	{
		if (IsOverlapped)
		{
			UE_LOG(LogTemp, Warning, TEXT("Open"));
		}
	}
}

void AInteractDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));
	Widget->SetVisibility(true);
	IsOverlapped = true;
}

void AInteractDoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End"));
	Widget->SetVisibility(false);
	IsOverlapped = false;
}
