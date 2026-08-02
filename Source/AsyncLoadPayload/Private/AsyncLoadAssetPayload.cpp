/**
* Copyright(C) 2025 | Created by Krileon
*/

#include "AsyncLoadPayload/Public/AsyncLoadAssetPayload.h"
#include "Engine/AssetManager.h"

void UAsyncLoadAssetPayload::Activate()
{
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		Asset.ToSoftObjectPath(),
		FStreamableDelegate::CreateUObject( this, &UAsyncLoadAssetPayload::OnCompleted )
	);
}

void UAsyncLoadAssetPayload::OnCompleted()
{
	UObject* LoadedObject = Asset.Get();

	Completed.Broadcast( LoadedObject, Payload );

	SetReadyToDestroy();
}

UAsyncLoadAssetPayload* UAsyncLoadAssetPayload::AsyncLoadAssetPayload(
	TSoftObjectPtr<UObject> Asset,
	FInstancedStruct Payload
) {
	UAsyncLoadAssetPayload* BlueprintNode = NewObject<UAsyncLoadAssetPayload>();

	BlueprintNode->Asset = Asset;
	BlueprintNode->Payload = Payload;

	return BlueprintNode;
}