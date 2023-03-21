#define NativeFunctions
#include <iostream>

#include "bogoscript.hpp"

bogoscript::TypeValueCompound bogoscriptNativeFunctions() {
	bogoscript::defineNativeFunction(L"myPrint"s, [](bogoscript::Args&& args) -> bogoscript::TypeValueCompound {
		bogoscript::outStream << "\x1B[32m"; // Makes all following characters green
		while (args) {
			bogoscript::outStream << static_cast<bogoscript::types::String::BaseType>(args.getNextVararg());
		}
		bogoscript::outStream << "\x1B[0m" << std::flush; // Sets text color back to normal
		return bogoscript::nullValue;
	});
	return bogoscript::nullValue;
}

#include "Main.bogo"
