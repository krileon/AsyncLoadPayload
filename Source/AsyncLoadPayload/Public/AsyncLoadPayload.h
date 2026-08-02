/**
* Copyright(C) 2025 | Created by Krileon
*/

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAsyncLoadPayloadModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
