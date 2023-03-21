#ifndef BOGOSCRIPT_COMPARISON_HPP
#define BOGOSCRIPT_COMPARISON_HPP

#include <map>
#include <sstream>
#include <memory>
#include <variant>
#include <algorithm>
#include <utility>
#include <type_traits>

#include "Args.hpp"
#include "TypeValueCompound.hpp"

namespace bogoscript {
    enum class ComparisonOperator {
        EQUALS_OP,
        NOT_EQUALS_OP,
        LESS_OP,
        GREATER_OP,
        LESS_EQUALS_OP,
        GREATER_EQUALS_OP,
        AND_OP,
        OR_OP
    };

    template <typename T>
    using ComparisonFunction = bool (*)(T&&, T&&) noexcept;

    template <typename T>
    static const std::map<ComparisonOperator, ComparisonFunction<T>> comparisonMap {
        {ComparisonOperator::EQUALS_OP, [](T&& v1, T&& v2) noexcept {return v1 == v2; }},
        {ComparisonOperator::NOT_EQUALS_OP, [](T&& v1, T&& v2) noexcept {return v1 != v2; }},
        {ComparisonOperator::LESS_OP, [](T&& v1, T&& v2) noexcept {return v1 < v2; }},
        {ComparisonOperator::GREATER_OP, [](T&& v1, T&& v2) noexcept {return v1 > v2; }},
        {ComparisonOperator::LESS_EQUALS_OP, [](T&& v1, T&& v2) noexcept {return v1 <= v2; }},
        {ComparisonOperator::GREATER_EQUALS_OP, [](T&& v1, T&& v2) noexcept {return v1 >= v2; }},
        {ComparisonOperator::AND_OP, [](T&& v1, T&& v2) noexcept {return v1 && v2; }},
        {ComparisonOperator::OR_OP, [](T&& v1, T&& v2) noexcept {return v1 || v2; }}
    };

    static const std::map<ComparisonOperator, bool> negativeComparisonResultMap {
        {ComparisonOperator::EQUALS_OP, false},
        {ComparisonOperator::NOT_EQUALS_OP, true},
        {ComparisonOperator::LESS_OP, false},
        {ComparisonOperator::GREATER_OP, false},
        {ComparisonOperator::LESS_EQUALS_OP, false},
        {ComparisonOperator::GREATER_EQUALS_OP, false},
        {ComparisonOperator::AND_OP, false},
        {ComparisonOperator::OR_OP, false}
    };

    template <typename T>
    static std::enable_if_t<std::is_base_of_v<types::Literal, T>, bool> compareTypedPair(Value&& value1, Value&& value2,
        ComparisonOperator comparisonOperator) noexcept {
        return comparisonMap<T>.at(comparisonOperator)(
            std::move(std::get<T>(value1)), std::move(std::get<T>(value2)));
    }

    inline bool comparePair(const Type type, Value&& value1, Value&& value2, const ComparisonOperator comparisonOperator) {
        switch (type) {
        case Type::NULL_TYPE:
            return compareTypedPair<types::NullValue>(std::move(value1), std::move(value2),
                comparisonOperator);
        case Type::STRING_TYPE:
            return compareTypedPair<types::String>(std::move(value1), std::move(value2),
                comparisonOperator);
        case Type::BOOL_TYPE:
            return compareTypedPair<types::Boolean>(std::move(value1), std::move(value2),
                comparisonOperator);
        case Type::INT_TYPE:
            return compareTypedPair<types::Integer>(std::move(value1), std::move(value2),
                comparisonOperator);
        default:
            throw "Tried to compare an object after its end of lifetime!";
        }
    }

    inline TypeValueCompound compare(Args&& bogoscriptInternalArgs, const ComparisonOperator comparisonOperator) {
        const auto& argsInitializerList = bogoscriptInternalArgs.getArgs();
        if (argsInitializerList.size() == 1) return nullValue;
        const auto type = bogoscriptInternalArgs[0].type;
        auto& value = *bogoscriptInternalArgs[0].value;
        if (!bogoscriptInternalArgs.isSingleTyped())
            return types::Boolean {negativeComparisonResultMap.at(comparisonOperator)};
        if (std::ranges::any_of(argsInitializerList.begin() + 1, argsInitializerList.end(), [&](const TypeValueCompound& el) {
            return !comparePair(type, std::move(value), std::move(*el.value),
                comparisonOperator);
            }))
            return falseValue;
            return trueValue;
    }
}

#endif