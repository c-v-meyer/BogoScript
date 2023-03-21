#ifndef BOGOSCRIPT_STREAMS_HPP
#define BOGOSCRIPT_STREAMS_HPP

#include <iostream>
#include <sstream>

namespace bogoscript {
	using StringStream = std::wostringstream;

	extern std::wistream& inStream;
	extern std::wostream& outStream;
	extern std::wostream& errStream;
}

#endif