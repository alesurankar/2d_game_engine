#pragma once
#include "Policy.h"
#include "Level.h"

namespace ales::log
{
	class SeverityLevelPolicy : public IPolicy {
	public:
		SeverityLevelPolicy(Level level);
		bool TransformFilter(Entry&) override;
	private:
		Level level_;
	};
}