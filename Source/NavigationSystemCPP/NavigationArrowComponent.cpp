// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationArrowComponent.h"



// Sets default values for this component's properties
UNavigationArrowComponent::UNavigationArrowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UNavigationArrowComponent::StartNavigate(AActor* OtherActorToNavigation)
{
	if(Arrow)
	{
		Arrow->SetRelativeRotation(FRotator(0,180,0));
	}
	if (OtherActor)
	{
		UpdateArrow();
	}
	return  false;
}

bool UNavigationArrowComponent::StopNavigate()
{
	return  true;
}

void UNavigationArrowComponent::UpdateArrow()
{

	FVector PlayerLocation = GetOwner()->GetActorLocation();
	PlayerLocation.Normalize(0.01f);
	FVector OtherActorLocation = OtherActor->GetActorLocation();
	OtherActorLocation.Normalize(0.01f);

	FVector OtherActor2Player =  -PlayerLocation +OtherActorLocation;
	OtherActor2Player.Normalize(0.01f);
	
	float FwdDotProduct = FVector::DotProduct(PlayerLocation.ForwardVector,OtherActor2Player);
	float RightDotProduct = FVector::DotProduct(OtherActor2Player,PlayerLocation.RightVector);
	
	FString DebugMsg = FString::Printf(TEXT("Fwd DOT: %f"), FwdDotProduct);
	GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Blue, DebugMsg);

	
	FString DebugMsg2 = FString::Printf(TEXT("Right DOT: %f"), RightDotProduct);
	GEngine->AddOnScreenDebugMessage(2, 0.0f, FColor::Orange, DebugMsg2);


	float AcosFwdDP = FGenericPlatformMath::Acos(FwdDotProduct);
	float AcosRightDP = FGenericPlatformMath::Acos(RightDotProduct);

	float yaw =FMath::RadiansToDegrees(AcosFwdDP)+FMath::RadiansToDegrees(AcosRightDP);
	
	UE_LOG(LogTemp, Warning, TEXT("F: %f= %f,R: %f= %f ; angel = %f" ),AcosFwdDP,FMath::RadiansToDegrees(AcosFwdDP),AcosRightDP,FMath::RadiansToDegrees(AcosRightDP),yaw);

	
	Arrow->SetRelativeRotation(FRotator(0,yaw,0));
}


// Called when the game starts
void UNavigationArrowComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNavigationArrowComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

