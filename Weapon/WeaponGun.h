// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/WeaponBase.h"
#include "WeaponGun.generated.h"

/**
 * 
 */
UCLASS()
class FPS_TESTGAME_API AWeaponGun : public AWeaponBase
{
	GENERATED_BODY()
public:
	AWeaponGun();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USkeletalMeshComponent * WeaponSkletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "WeponeBasicValue")
	FName CurrentMuzzleName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeponeBasicValue")
	FName ShellEjectionName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeponeBasicValue")
	FTransform CurrentMuzzleTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeponeBasicValue")
		TSubclassOf<AActor> BulletActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
		UParticleSystem * FireParticle;		//开火特效
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
		UParticleSystem * FireMuzzleSmokeParticle;		//开火烟特效
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
		UParticleSystem * FireShellEjectionParticle;		//开火弹壳特效
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponSound")
		USoundCue * FireSound;		//开火音效
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual bool OnAttack()override;
	virtual bool OffAttack()override;
	
};
