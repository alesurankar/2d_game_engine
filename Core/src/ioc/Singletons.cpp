#include "Singletons.h"

namespace ales::ioc {
	Singletons& Sing() {
		static Singletons sing;
		return sing;
	}
}