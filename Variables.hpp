#ifndef BOGOSCRIPT_VARIABLES_HPP
#define BOGOSCRIPT_VARIABLES_HPP

#include <map>
#include <algorithm>
#include <utility>
#include <type_traits>

#include "TypeValueCompound.hpp"

namespace bogoscript {
    inline std::map<types::String::BaseType, std::map<types::String::BaseType, TypeValueCompound>>
        variableMap = {{L"", std::map<types::String::BaseType, TypeValueCompound>()}};
    inline auto& globalVariableMap = variableMap.at(L"");

    inline TypeValueCompound& getVariable(types::String::BaseType&& scopeName, const types::String::BaseType& varName) {
        if (const auto globalIt = variableMap.at(L"").find(varName); globalIt == globalVariableMap.end()) {
            auto& scopedVariableMap = variableMap.at(scopeName);
            if (const auto scopedIt = scopedVariableMap.find(varName); scopedIt == scopedVariableMap.end())
                throw "Tried to access a variable that doesn't exist!";
            else
                return scopedIt->second;
        } else {
            return globalIt->second;
        }
    }

    inline TypeValueCompound& setVariable(types::String::BaseType&& scopeName, const types::String::BaseType& varName,
        TypeValueCompound&& value) {
        if (!scopeName.empty() && globalVariableMap.contains(varName))
            throw "Name of local variable collides with a global variable!";
        if (!variableMap.contains(scopeName))
            variableMap[scopeName] = std::map<types::String::BaseType, TypeValueCompound>();
        auto& scopedVariableMap = variableMap.at(scopeName);
        if (const auto it = scopedVariableMap.find(varName); it != scopedVariableMap.end()) scopedVariableMap.erase(it);
        scopedVariableMap.insert({varName, std::move(value)});
        return scopedVariableMap.at(varName);
    }

    inline TypeValueCompound deleteVariable(types::String::BaseType&& scopeName, const types::String::BaseType& varName) {
        const auto globalIt = globalVariableMap.find(varName);
        if (globalIt != globalVariableMap.end()) {
            globalVariableMap.erase(varName);
        } else {
            auto& scopedVariableMap = variableMap.at(scopeName);
            if (const auto scopedIt = scopedVariableMap.find(varName); scopedIt == scopedVariableMap.end())
                throw "Tried to delete non-existing variable!";
            else
                scopedVariableMap.erase(scopedIt);
        }
        // TODO: return value
        return nullValue;
    }
}

#endif