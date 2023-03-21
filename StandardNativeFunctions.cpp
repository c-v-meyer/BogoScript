#include "StandardNativeFunctions.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <variant>
#include <algorithm>
#include <utility>
#include <type_traits>

#include "Args.hpp"
#include "Comparison.hpp"
#include "Functions.hpp"
#include "TypeValueCompound.hpp"
#include "Integer.hpp"
#include "Boolean.hpp"
#include "String.hpp"
#include "Streams.hpp"

namespace bogoscript {
    TypeValueCompound standardNativeFunctions() {
        using namespace std::string_literals;
        defineNativeFunction(L"!"s, [](Args&& args) -> TypeValueCompound {
            if (args[0].type != Type::BOOL_TYPE)
                throw "Not-operator only applicable to booleans!";
            if (!std::get<types::Boolean>(*args[0].value))
                return trueValue;
            return falseValue;
            });
        defineNativeFunction(L"="s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::EQUALS_OP);
            });
        defineNativeFunction(L"!="s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::NOT_EQUALS_OP);
            });
        defineNativeFunction(L"<"s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::LESS_OP);
            });
        defineNativeFunction(L">"s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::GREATER_OP);
            });
        defineNativeFunction(L"<="s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::LESS_EQUALS_OP);
            });
        defineNativeFunction(L">="s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::GREATER_EQUALS_OP);
            });
        defineNativeFunction(L"&&"s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::AND_OP);
            });
        defineNativeFunction(L"||"s, [](Args&& args) -> TypeValueCompound {
            return compare(std::move(args), ComparisonOperator::OR_OP);
            });
        defineNativeFunction(L"+"s, [](Args&& rawArgs) -> TypeValueCompound {
            auto& args = rawArgs.getArgs();
            const auto type = rawArgs[0].type;
            if (rawArgs.containsType(Type::STRING_TYPE)) {
                StringStream buffer;
                for (auto& arg : args) {
                    switch (arg.type) {
                    case Type::NULL_TYPE:
                        break;
                    case Type::STRING_TYPE:
                        buffer << static_cast<types::String::BaseType>(arg);
                        break;
                    case Type::BOOL_TYPE:
                        buffer << static_cast<types::Boolean::BaseType>(arg);
                        break;
                    case Type::INT_TYPE:
                        buffer << static_cast<types::Integer::BaseType>(arg);
                        break;
                    default:
                        throw "Tried to add an object after its lifetime!";
                    }
                }
                return buffer.str();
            } else if (type != Type::INT_TYPE || !rawArgs.isSingleTyped()) {
                throw "Tried to add invalid types!";
            }
            types::Integer::BaseType buffer = 0;
            for (auto& arg : args) {
                buffer += static_cast<types::Integer::BaseType>(arg);
            }
            return buffer;
            });
        defineNativeFunction(L"-"s, [](Args&& rawArgs) -> TypeValueCompound {
            auto& args = rawArgs.getArgs();
            types::Integer::BaseType buffer = 0;
            for (auto& arg : args) {
                if (arg.type != Type::INT_TYPE)
                    throw "Tried to subtract a non-integer type";
                buffer -= static_cast<types::Integer::BaseType>(arg);
            }
            buffer += std::get<types::Integer>(*rawArgs[0].value) << 1;
            return buffer;
            });
        defineNativeFunction(L"print"s, [](Args&& args) -> TypeValueCompound {
            while (args) {
				outStream << static_cast<types::String::BaseType>(args.getNextVararg());
            }
            outStream << std::flush;
            return nullValue;
            });
        defineNativeFunction(L"println"s, [](Args&& args) -> TypeValueCompound {
            while (args) {
                outStream << static_cast<types::String::BaseType>(args.getNextVararg());
            }
            outStream << std::endl;
            return nullValue;
            });
        defineNativeFunction(L"readStr"s, [](Args&& args) -> TypeValueCompound {
            types::String::BaseType buffer;
            inStream >> buffer;
            return buffer;
            });
        defineNativeFunction(L"readNum"s, [](Args&& args) -> TypeValueCompound {
            types::String::BaseType buffer;
            inStream >> buffer;
            if (buffer.empty() || (buffer.size() == 2 && (buffer[1] == 'x' || buffer[1] == 'X')))
                return nullValue;
            int base;
            if (buffer[0] == '0')
                base = 8;
            else if (buffer.size() > 2 && (buffer[1] == 'x' || buffer[1] == 'X'))
                base = 16;
            else
                base = 10;
            types::Integer::BaseType result;
            try {
                result = std::stoll(buffer, nullptr, base);
            } catch (const std::invalid_argument&) {
                return nullValue;
            } catch (const std::out_of_range&) {
                return nullValue;
            }
            return result;
            });
        return nullValue;
    }
}