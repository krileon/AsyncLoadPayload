/**
* Copyright(C) 2025 | Created by Krileon
*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Delegates/IDelegateInstance.h"
#include "Engine/StreamableManager.h"
#include "StructUtils/InstancedStruct.h"
#include "AsyncLoadAssetClassPayload.generated.h"

UCLASS( Blueprintable )
class ASYNCLOADPAYLOAD_API UAsyncLoadAssetClassPayload : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FOnAsyncLoadAssetClassPayloadSignature, UClass*, Class, FInstancedStruct, Payload );

	UPROPERTY( BlueprintAssignable, Category = "AsyncLoadPayload" )
		FOnAsyncLoadAssetClassPayloadSignature Completed;

	UFUNCTION( BlueprintCallable, meta = ( BlueprintInternalUseOnly = "true" ), Category = "AsyncLoadPayload", DisplayName = "Async Load Asset Class w/ Payload" )
		static UAsyncLoadAssetClassPayload* AsyncLoadAssetClassPayload(
			TSoftClassPtr<UObject> AssetClass,
			FInstancedStruct Payload
		);

	virtual void Activate() override;

protected:
	UPROPERTY()
		TSoftClassPtr<UObject> AssetClass;

	UPROPERTY()
		FInstancedStruct Payload;

	void OnCompleted();
};