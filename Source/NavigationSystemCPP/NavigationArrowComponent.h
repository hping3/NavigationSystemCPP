// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/ArrowComponent.h"

#include "NavigationArrowComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NAVIGATIONSYSTEMCPP_API UNavigationArrowComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UNavigationArrowComponent();

	UPROPERTY(EditAnywhere,Category="NavigationArrowComponet")
	AActor* OtherActor;

	UArrowComponent* Arrow;

	UFUNCTION(BlueprintCallable,Category="NavigationArrowComponet")
	virtual bool StartNavigate(AActor* OtherActorToNavigation);
	
	UFUNCTION(BlueprintCallable,Category="NavigationArrowComponet")
	virtual bool StopNavigate();

	UFUNCTION(BlueprintCallable,Category="NavigationArrowComponet")
	void UpdateArrow();

	bool IsNavigaiting = false;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
