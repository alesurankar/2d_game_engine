#include "Container.h"

namespace ales
{
	namespace ioc
	{
		Container& Get() noexcept
		{
			static Container container;
			return container;
		}
	}
}