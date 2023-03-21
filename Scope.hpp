#ifndef BOGOSCRIPT_SCOPE_HPP
#define BOGOSCRIPT_SCOPE_HPP

#include <map>
#include <string>

#include "Variables.hpp"

namespace bogoscript {
    inline void clearScope(const types::String::BaseType& scopeName) {
        const auto it = globalVariableMap.find(scopeName);
        if (it != globalVariableMap.end())
            globalVariableMap.erase(it);
    }
}

#endif