// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2021 Doğa Can Yanıkoğlu
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/dyanikoglu/ALSV4_CPP
// Original Author: Doğa Can Yanıkoğlu
// Contributors:  

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FALSV4CPP_Module : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

