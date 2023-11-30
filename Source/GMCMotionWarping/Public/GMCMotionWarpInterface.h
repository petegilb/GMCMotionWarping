// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GMCMotionWarpInterface.generated.h"

class UGMC_OrganicMovementCmp;

UINTERFACE()
class UGMCMotionWarpInterface : public UInterface{
	GENERATED_BODY()
};

/**
 * 
 */
class GMCMOTIONWARPING_API IGMCMotionWarpInterface{
	GENERATED_BODY()

	
public:
	virtual USkeletalMeshComponent* GetMotionWarpMesh();
	virtual float GetCollisionHalfHeight();
	virtual FQuat GetRotationOffset();
	virtual FVector GetTranslationOffset();
	virtual FAnimMontageInstance* GetRootMotionAnimMontageInstance(USkeletalMeshComponent* Mesh) const;
	virtual UGMC_OrganicMovementCmp* GetOrganicMovementCmp();
};
