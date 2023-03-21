#include "String.hpp"

#include <string>
#include <cstring>
#include <new>

#include "Literal.hpp"

namespace bogoscript {
	namespace types {
		thread_local wchar_t String::conversionBuffer[conversionBufferSize] = {0};

		
	}
}
