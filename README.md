# GMCMotionWarping
Epic's Motion Warping plugin for UE5 but edited to work with the General Movement Component
  
## Links
GMC: https://www.unrealengine.com/marketplace/en-US/product/general-movement-component  
Unreal on Github: https://www.unrealengine.com/en-US/ue-on-github  
  
## Warning
This is still a work in progress and isn't fully functional for MP at all  

## Getting Started  
  
There are a couple of required steps to get this up and running:
1. Add this plugin and make sure its enabled (you'll need to compile it)
2. Implement the IGMCMotionWarpInterface on your APawn and override the functions in that interface (example at the bottom of the readme)
3. Add a delegate to the GMCOrganicMovementComponent header file:
```
DECLARE_DELEGATE_RetVal_ThreeParams(FTransform, FOnProcessRootMotion, const FTransform&, UGMC_OrganicMovementCmp*, float)
and put the following in the public section
FOnProcessRootMotion ProcessRootMotionPreConvertToWorld;
```
4. Execute that delegate and add to the root motion animation transform by putting the following code in the MontageUpdate function.
```
// Root motion calculations from motion warping
FTransform PreProcessedRootMotion = ProcessRootMotionPreConvertToWorld.IsBound() ? ProcessRootMotionPreConvertToWorld.Execute(RootMotionParams.GetRootMotionTransform(), this, DeltaSeconds) : FTransform();
FTransform WorldSpaceRootMotionTransform = SkeletalMesh->ConvertLocalRootMotionToWorld(RootMotionParams.GetRootMotionTransform() + PreProcessedRootMotion);

// Save the root motion transform in world space.
RootMotionParams.Set(WorldSpaceRootMotionTransform);
```

it should replace this line
```
RootMotionParams.Set(SkeletalMesh->ConvertLocalRootMotionToWorld
```

5. Proceed using motion warping like you usually would! (It only works with the gmc's playmontage functionality)

### Here's an example of the functions you should override in your pawn
```
USkeletalMeshComponent* ATSS_PawnBase::GetMotionWarpMesh(){
	return Mesh;
}

float ATSS_PawnBase::GetCollisionHalfHeight(){
	return Capsule->GetScaledCapsuleHalfHeight();
}

FQuat ATSS_PawnBase::GetRotationOffset(){
	return Mesh->GetRelativeRotation().Quaternion();
}

FVector ATSS_PawnBase::GetTranslationOffset(){
	return Mesh->GetRelativeLocation();
}

UGMC_OrganicMovementCmp* ATSS_PawnBase::GetOrganicMovementCmp(){
	return GMC;
}
```
