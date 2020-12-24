// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAI.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AI_Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../../characters/mainChar_Fox.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include <BehaviorTree/BlackboardComponent.h>
#include "Perception/AIPerceptionTypes.h"


// Sets default values
ABaseAI::ABaseAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AI_Sight = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Sight_Percep"));
	
	Sense_sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));

	Sense_sight->SightRadius = 2500;
	Sense_sight->LoseSightRadius = 3000;
	Sense_sight->PeripheralVisionAngleDegrees = 60;
	Sense_sight->DetectionByAffiliation.bDetectEnemies = true;
	Sense_sight->DetectionByAffiliation.bDetectFriendlies = true;
	Sense_sight->DetectionByAffiliation.bDetectNeutrals = true;

	

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
	
	GetMesh()->bRenderCustomDepth = true;
	GetMesh()->CustomDepthStencilValue = 2;
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
	bool isSensed = Stimulus.WasSuccessfullySensed();
	

	AmainChar_Fox* fox = Cast<AmainChar_Fox>(Actor);

	UBlackboardComponent* bb = UAIBlueprintHelperLibrary::GetBlackboard(this);
	
	if (bb && fox) {
		if (isSensed) {
			bb->SetValueAsBool("isAware", isSensed);
			bb->SetValueAsVector("LastSeenPawn", Stimulus.StimulusLocation);
		}
		bb->SetValueAsBool("CanSeePawn", isSensed);
	}
	


}



void ABaseAI :: SetVelocity(bool bDoWalk) {
	if (bDoWalk) {
		GetCharacterMovement()->MaxWalkSpeed = walkVelocity;
	}
	else {
		GetCharacterMovement()->MaxWalkSpeed = RunVelocity;
	}
}


