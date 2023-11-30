// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GMCMotionWarping : ModuleRules
{
	public GMCMotionWarping(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",		
				"Engine",
				"NetCore",
				"GMCCore"
			}
		);			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore"
			}
		);
	}
}
