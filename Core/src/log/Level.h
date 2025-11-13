#pragma once
#include <string>

namespace ales::log 
{
	enum class Level {
		Trace,
		Debug,
		Info,
		Warn,
		Error,
		Fatal,
	};

	std::wstring GetLevelName(Level);
}