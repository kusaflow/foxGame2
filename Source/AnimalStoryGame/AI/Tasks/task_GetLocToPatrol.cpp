// Fill out your copyright notice in the Description page of Project Settings.


#include "task_GetLocToPatrol.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/BehaviorTreeComponent.h>
#include "../Base/AI_Controller.h"


Utask_GetLocToPatrol :: Utask_GetLocToPatrol(FObjectInitializer const& obj_init) {
	NodeName = "GetPointToMove";
}

EBTNodeResult::Type Utask_GetLocToPatrol :: ExecuteTask(class UBehaviorTreeComponent& owner_comp, uint8* node_memory) {

	AAI_Controller *aic = Cast<AAI_Controller>(owner_comp.GetAIOwner());
	UBlackboardComponent* bb = aic->GetBlackboardComponent();
	

	return EBTNodeResult::Succeeded;
}

