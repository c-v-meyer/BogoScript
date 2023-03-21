#include "Streams.hpp"

#include <iostream>

namespace bogoscript {
	std::wistream& inStream = std::wcin;
	std::wostream& outStream = std::wcout;
	std::wostream& errStream = std::wcerr;
}
