#ifndef BOGOSCRIPT_FUNCTIONS_HPP
#define BOGOSCRIPT_FUNCTIONS_HPP

#include <map>
#include <algorithm>
#include <utility>
#include <type_traits>

#include "Args.hpp"
#include "TypeValueCompound.hpp"

namespace bogoscript {
    using Function = TypeValueCompound(*)(
        TypeValueCompound&&,
        const std::initializer_list<TypeValueCompound>&);
    using NativeFunction = TypeValueCompound(*)(Args&&);

    static std::map<types::String::BaseType, Function> functionMap;
    static std::map<types::String::BaseType, NativeFunction> nativeFunctionMap;

    inline TypeValueCompound defineFunction(types::String::BaseType&& funName, Function fun) {
        if (functionMap.contains(funName))
            throw "Tried to redefine a function!";
        functionMap.insert({funName, fun});
        return nullValue;
    }

    inline TypeValueCompound defineFunction(types::String::BaseType&& funName) {
        if (!nativeFunctionMap.contains(funName))
            throw "Corresponding native function doesn't exist!";
        return defineFunction(std::move(funName), [](TypeValueCompound&& bogoscriptInternalScopeName, const std::initializer_list<TypeValueCompound>& bogoscriptInternalArgs) -> TypeValueCompound {
            Args args {bogoscriptInternalArgs};
            return nativeFunctionMap.at(static_cast<types::String::BaseType>(bogoscriptInternalScopeName))(std::move(args));
        });
    }

    inline TypeValueCompound defineNativeFunction(const types::String::BaseType& funName, NativeFunction fun) {
        if (nativeFunctionMap.contains(funName))
            throw "Tried to redefine a native function!";
        nativeFunctionMap.insert({funName, fun});
        return nullValue;
    }

    inline TypeValueCompound call(const types::String::BaseType& name,
        const std::initializer_list<TypeValueCompound>& args) {
        //return functionMap[name](TypeValueCompound(name), args);
        const auto& function = functionMap[name];
        if (function == nullptr) {
            throw "Tried to call a non-existent function";
            return TypeValueCompound();
        }
        return function(TypeValueCompound(name), args);
    }

    inline TypeValueCompound call(const types::String::BaseType& name) {
        return call(name, {});
    }
}

#endif