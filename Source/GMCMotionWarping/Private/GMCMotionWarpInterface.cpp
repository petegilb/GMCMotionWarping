// Fill out your copyright notice in the Description page of Project Settings.


#include "GMCMotionWarpInterface.h"

USkeletalMeshComponent* IGMCMotionWarpInterface::GetMotionWarpMesh(){
	return nullptr;
}

float IGMCMotionWarpInterface::GetCollisionHalfHeight(){
	return 0.f;
}

FQuat IGMCMotionWarpInterface::GetRotationOffset(){
	return FQuat::Identity;
}

FVector IGMCMotionWarpInterface::GetTranslationOffset(){
	return FVector();
}

FAnimMontageInstance* IGMCMotionWarpInterface::GetRootMotionAnimMontageInstance(USkeletalMeshComponent* Mesh) const{
	return Mesh && Mesh->GetAnimInstance() ? Mesh->GetAnimInstance()->GetRootMotionMontageInstance() : nullptr;
}

UGMC_OrganicMovementCmp* IGMCMotionWarpInterface::GetOrganicMovementCmp(){
	return nullptr;
}
