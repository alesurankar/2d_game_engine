#pragma once
#include "SeverityLevelPolicy.h"
#include "Entry.h"

namespace ales::log
{
	SeverityLevelPolicy::SeverityLevelPolicy(Level level)
		:
		level_{level}
	{ }
	bool SeverityLevelPolicy::TransformFilter(Entry& e)
	{
		return e.level_ <= level_;
	}
}