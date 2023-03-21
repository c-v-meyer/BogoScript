#ifndef BOGOSCRIPT_BOOLEAN_HPP
#define BOGOSCRIPT_BOOLEAN_HPP

#include "Literal.hpp"

namespace bogoscript {
	namespace types {
        struct Boolean final : Literal {
            using BaseType = bool;
            BaseType value;
            explicit Boolean(const BaseType value) noexcept
                : value {value} {}
            constexpr operator BaseType() const noexcept {
                return value;
            }
            friend constexpr bool operator==(const Boolean& value1, const Boolean& value2) noexcept;
            friend constexpr bool operator!=(const Boolean& value1, const Boolean& value2) noexcept;
            friend inline bool operator<(const Boolean& value1, const Boolean& value2);
            friend inline bool operator>(const Boolean& value1, const Boolean& value2);
            friend inline bool operator<=(const Boolean& value1, const Boolean& value2);
            friend inline bool operator>=(const Boolean& value1, const Boolean& value2);
            friend constexpr bool operator&&(const Boolean& value1, const Boolean& value2) noexcept;
            friend constexpr bool operator||(const Boolean& value1, const Boolean& value2) noexcept;
        };
        constexpr bool operator==(const Boolean& value1, const Boolean& value2) noexcept {
            return value1.value == value2.value;
        }
        constexpr bool operator!=(const Boolean& value1, const Boolean& value2) noexcept {
            return value1.value != value2.value;
        }
        inline bool operator<(const Boolean&, const Boolean&) {
            throw "Tried to <-compare two booleans!";
        }
        inline bool operator>(const Boolean&, const Boolean&) {
            throw "Tried to >-compare two booleans!";
        }
        inline bool operator<=(const Boolean&, const Boolean&) {
            throw "Tried to <=-compare two booleans!";
        }
        inline bool operator>=(const Boolean&, const Boolean&) {
            throw "Tried to >=-compare two booleans!";
        }
        constexpr bool operator&&(const Boolean& value1, const Boolean& value2) noexcept {
            return value1.value && value2.value;
        }
        constexpr bool operator||(const Boolean& value1, const Boolean& value2) noexcept {
            return value1.value || value2.value;
        }
	}
}

#endif