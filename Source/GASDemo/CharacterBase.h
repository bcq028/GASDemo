// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AttributeSetBase.h"
#include "EnhancedInputSubsystemInterface.h"
#include "CharacterBase.generated.h"

UCLASS()
class GASDEMO_API ACharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent *CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent *FollowCamera;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UAbilitySystemComponent* AbilitySystem;

	UFUNCTION(BlueprintCallable)
	void GiveAbility(TSubclassOf<UGameplayAbility> Ability);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAttributeSetBase* AttributeSet;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UInputMappingContext * InputMapContext;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};
