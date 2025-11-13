#pragma once
namespace ales::log
{
	struct Entry;

	class IChannel {
	public:
		virtual void Submit(Entry&) = 0;
	};
}