#ifndef BOGOSCRIPT_INTEGER_HPP
#define BOGOSCRIPT_INTEGER_HPP

#include "Literal.hpp"

namespace bogoscript {
	namespace types {
        struct Integer final : Literal {
            using BaseType = long long;
            BaseType value;
            Integer(const BaseType value) noexcept
                : value {value} {}
            constexpr operator BaseType() const noexcept {
                return value;
            }
            friend constexpr bool operator==(const Integer& value1, const Integer& value2) noexcept;
            friend constexpr bool operator!=(const Integer& value1, const Integer& value2) noexcept;
            friend constexpr bool operator<(const Integer& value1, const Integer& value2) noexcept;
            friend constexpr bool operator>(const Integer& value1, const Integer& value2) noexcept;
            friend constexpr bool operator<=(const Integer& value1, const Integer& value2) noexcept;
            friend constexpr bool operator>=(const Integer& value1, const Integer& value2) noexcept;
            friend inline bool operator&&(const Integer& value1, const Integer& value2);
            friend inline bool operator||(const Integer& value1, const Integer& value2);
        };
        constexpr bool operator==(const Integer& value1, const Integer& value2) noexcept {
            return value1.value == value2.value;
        }
        constexpr bool operator!=(const Integer& value1, const Integer& value2) noexcept {
            return value1.value == value2.value;
        }
        constexpr bool operator<(const Integer& value1, const Integer& value2) noexcept {
            return value1.value < value2.value;
        }
        constexpr bool operator>(const Integer& value1, const Integer& value2) noexcept {
            return value1.value > value2.value;
        }
        constexpr bool operator<=(const Integer& value1, const Integer& value2) noexcept {
            return value1.value <= value2.value;
        }
        constexpr bool operator>=(const Integer& value1, const Integer& value2) noexcept {
            return value1.value >= value2.value;
        }
        inline bool operator&&(const Integer&, const Integer&) {
            throw "Tried to &&-compare two integers!";
        }
        inline bool operator||(const Integer&, const Integer&) {
            throw "Tried to ||-compare two integers!";
        }
	}
}

#endif