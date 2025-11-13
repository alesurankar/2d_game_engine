#include "EntryBuilder.h"
#include "Channel.h"

namespace ales::log
{
	EntryBuilder::EntryBuilder(const wchar_t* sourceFile, const wchar_t* sourceFunctionName, int sourceLine)
		:
		Entry{
			.level_ = Level::Error,
			.sourceFile_ = sourceFile,
			.courceFunctionName_ = sourceFunctionName,
			.sourceLine_ = sourceLine,
		}
	{}

	EntryBuilder& ales::log::EntryBuilder::note(std::wstring note)
	{
		note_ = std::move(note);
		return *this;
	}

	EntryBuilder& ales::log::EntryBuilder::level(Level level)
	{
		level_ = level;
		return *this;
	}

	EntryBuilder& ales::log::EntryBuilder::chan(IChannel* pChan)
	{
		pDest_ = pChan;
		return *this;
	}
	EntryBuilder::~EntryBuilder()
	{
		if (pDest_) {
			pDest_->Submit(*this);
		}
	}
}