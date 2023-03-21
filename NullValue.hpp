#ifndef BOGOSCRIPT_NULLVALUE_HPP
#define BOGOSCRIPT_NULLVALUE_HPP

#include <cstddef>

#include "Literal.hpp"

namespace bogoscript {
	namespace types {
        struct NullValue final : Literal {
            using BaseType = std::nullptr_t;
            BaseType value;
            explicit NullValue(const BaseType value) noexcept
                : value {value} {}
            constexpr operator BaseType() const noexcept {
                return value;
            }
            friend constexpr bool operator==(const NullValue& value1, const NullValue& value2) noexcept;
            friend constexpr bool operator!=(const NullValue& value1, const NullValue& value2) noexcept;
            friend constexpr bool operator<(const NullValue& value1, const NullValue& value2) noexcept;
            friend constexpr bool operator>(const NullValue& value1, const NullValue& value2) noexcept;
            friend constexpr bool operator<=(const NullValue& value1, const NullValue& value2) noexcept;
            friend constexpr bool operator>=(const NullValue& value1, const NullValue& value2) noexcept;
            friend inline bool operator&&(const NullValue& value1, const NullValue& value2);
            friend inline bool operator||(const NullValue& value1, const NullValue& value2);
        };
        constexpr bool operator==(const NullValue&, const NullValue&) noexcept {
            return true;
        }
        constexpr bool operator!=(const NullValue&, const NullValue&) noexcept {
            return false;
        }
        constexpr bool operator<(const NullValue&, const NullValue&) noexcept {
            return false;
        }
        constexpr bool operator>(const NullValue&, const NullValue&) noexcept {
            return false;
        }
        constexpr bool operator<=(const NullValue&, const NullValue&) noexcept {
            return true;
        }
        constexpr bool operator>=(const NullValue&, const NullValue&) noexcept {
            return true;
        }
        inline bool operator&&(const NullValue&, const NullValue&) {
            throw "Tried to &&-compare two null values!";
        }
        inline bool operator||(const NullValue&, const NullValue&) {
            throw "Tried to ||-compare two null values!";
        }
	}
}

#endif