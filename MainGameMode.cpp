// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "Kismet/GameplayStatics.h"


void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction
		("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);
}

void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainGameMode::OnSwitch()
{
	if (Switched)
	{
		FVector NewLocation = GetWorld()->GetFirstPlayerController()->
			GetPawn()->GetActorLocation();

		NewLocation.X = 1206.0f;

		GetWorld()->GetFirstPlayerController()->
			GetPawn()->SetActorLocation(NewLocation);
	}
	else
	{
		FVector NewLocation = GetWorld()->GetFirstPlayerController()->
			GetPawn()->GetActorLocation();

		NewLocation.X = 231.0f;

		GetWorld()->GetFirstPlayerController()->
			GetPawn()->SetActorLocation(NewLocation);
	}

	Switched = !Switched;
}

void AMainGameMode::OnGameOver(bool win)
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}
