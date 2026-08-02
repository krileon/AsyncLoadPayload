/**
* Copyright(C) 2025 | Created by Krileon
*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Delegates/IDelegateInstance.h"
#include "Engine/StreamableManager.h"
#include "StructUtils/InstancedStruct.h"
#include "AsyncLoadAssetPayload.generated.h"

UCLASS( Blueprintable )
class ASYNCLOADPAYLOAD_API UAsyncLoadAssetPayload : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FOnAsyncLoadAssetPayloadSignature, UObject*, Object, FInstancedStruct, Payload );		

	UPROPERTY( BlueprintAssignable, Category = "AsyncLoadPayload" )
		FOnAsyncLoadAssetPayloadSignature Completed;

	UFUNCTION( BlueprintCallable, meta = ( BlueprintInternalUseOnly = "true" ), Category = "AsyncLoadPayload", DisplayName = "Async Load Asset w/ Payload" )
		static UAsyncLoadAssetPayload* AsyncLoadAssetPayload(
			TSoftObjectPtr<UObject> Asset,
			FInstancedStruct Payload
		);

	virtual void Activate() override;

protected:
	UPROPERTY()
		TSoftObjectPtr<UObject> Asset;

	UPROPERTY()
		FInstancedStruct Payload;

	void OnCompleted();
};