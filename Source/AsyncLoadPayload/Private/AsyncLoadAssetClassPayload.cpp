/**
* Copyright(C) 2025 | Created by Krileon
*/

#include "AsyncLoadPayload/Public/AsyncLoadAssetClassPayload.h"
#include "Engine/AssetManager.h"

void UAsyncLoadAssetClassPayload::Activate()
{
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		AssetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateUObject( this, &UAsyncLoadAssetClassPayload::OnCompleted )
	);
}

void UAsyncLoadAssetClassPayload::OnCompleted()
{
	UClass* LoadedClass = AssetClass.Get();

	Completed.Broadcast( LoadedClass, Payload );

	SetReadyToDestroy();
}

UAsyncLoadAssetClassPayload* UAsyncLoadAssetClassPayload::AsyncLoadAssetClassPayload(
	TSoftClassPtr<UObject> AssetClass,
	FInstancedStruct Payload
) {
	UAsyncLoadAssetClassPayload* BlueprintNode = NewObject<UAsyncLoadAssetClassPayload>();

	BlueprintNode->AssetClass = AssetClass;
	BlueprintNode->Payload = Payload;

	return BlueprintNode;
}