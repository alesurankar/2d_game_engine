#pragma once
#include "Channel.h"
#include "EntryBuilder.h"

namespace ales::log
{
	IChannel* GetDefaultChannel();
	
	void Boot();
}

#define alelog log::EntryBuilder{ __FILEW__, __FUNCTIONW__, __LINE__ }.chan(log::GetDefaultChannel())