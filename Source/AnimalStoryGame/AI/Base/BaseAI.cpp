// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAI.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AI_Controller.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ABaseAI::ABaseAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AI_Sight = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Sight_Percep"));
	
	Sense_sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));

	Sense_sight->SightRadius = 2500;
	Sense_sight->LoseSightRadius = 3000;
	Sense_sight->PeripheralVisionAngleDegrees = 80;
	

	AI_Sight->ConfigureSense(*Sense_sight);




	if (AI_Sight)
		AI_Sight->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAI::Sight_Perception_Updated);


	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	
}

// Called when the game starts or when spawned
void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseAI :: Sight_Perception_Updated(AActor* Actor, FAIStimulus Stimulus) {
	
}