#include <iostream>
#include <Core/src/log/EntryBuilder.h>
#include <Core/src/log/Channel.h>
#include <Core/src/log/MsvcDebugDriver.h>
#include <Core/src/log/TextFormatter.h>
#include <Core/src/log/SeverityLevelPolicy.h>

using namespace ales;
using namespace std::string_literals;

#define alelog log::EntryBuilder{ __FILEW__, __FUNCTIONW__, __LINE__ }.chan(pChan.get())

std::unique_ptr<log::IChannel> pChan;

void f()
{
	alelog.error(L"oops!");
}

#define alelog log::EntryBuilder{ __FILEW__, __FUNCTIONW__, __LINE__ }.chan(pChan.get())

int main()
{
	pChan = std::make_unique<log::Channel>(
		std::vector<std::shared_ptr<log::IDriver>>{
		std::make_shared<log::MsvcDebugDriver>(std::make_unique<log::TextFormatter>())
		}
	);
	pChan->AttachPolicy(std::make_unique<log::SeverityLevelPolicy>(log::Level::Error));
	alelog.fatal(L"Oh nooo!");
	alelog.warn(L"huh");
	f();

	return 0;
}