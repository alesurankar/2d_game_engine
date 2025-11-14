#pragma once
#include <string>

namespace ales::utl
{
	std::wstring ToWide(const std::string& narrow);
	std::string ToNarrow(const std::wstring& wide);
}