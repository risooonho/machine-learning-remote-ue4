// Fill out your copyright notice in the Description page of Project Settings.

#include "TensorflowBaseComponent.h"
#include "TensorflowRemote.h"
#include "CULambdaRunnable.h"

UTensorflowBaseComponent::UTensorflowBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsConnectedToBackend = false;
}

void UTensorflowBaseComponent::SendJsonInput(const FString& InputData)
{
	FString Result = TEXT("not implemented");
	UE_LOG(TensorflowBaseLog, Warning, TEXT("%s"), *Result);
	OnResult.Broadcast(Result);
}

void UTensorflowBaseComponent::SendJsonInputGraphResult(const FString& InputData, FString& Result, struct FLatentActionInfo LatentInfo)
{
	Result = TEXT("not implemented");

	UE_LOG(TensorflowBaseLog, Warning, TEXT("%s"), *Result);

	FCULatentAction* LatentAction = FCULatentAction::CreateLatentAction(LatentInfo, this);
	LatentAction->Call();	//resume the latent action
}
