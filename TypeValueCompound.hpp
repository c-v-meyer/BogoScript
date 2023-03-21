#ifndef BOGOSCRIPT_TYPEVALUECOMPOUND_HPP
#define BOGOSCRIPT_TYPEVALUECOMPOUND_HPP

#include "Type.hpp"
#include "Value.hpp"

namespace bogoscript {
    extern types::NullValue nullValue;
    extern types::Boolean trueValue;
    extern types::Boolean falseValue;

    struct TypeValueCompound {
    private:
        static ValuePtr errorValuePtr;
        static ValuePtr nullValuePtr;
        static ValuePtr trueValuePtr;
        static ValuePtr falseValuePtr;

    public:
        Type type;
        ValuePtr value;

        [[maybe_unused]] TypeValueCompound();
        TypeValueCompound(const TypeValueCompound&);
        TypeValueCompound(TypeValueCompound&&) noexcept;
        TypeValueCompound& operator=(const TypeValueCompound&);
        TypeValueCompound& operator=(TypeValueCompound&&) noexcept;
        TypeValueCompound(types::NullValue) noexcept;
        TypeValueCompound(types::String) noexcept;
        TypeValueCompound(types::String::BaseType) noexcept;
        TypeValueCompound(const char*) noexcept;
        TypeValueCompound(const wchar_t*) noexcept;
        TypeValueCompound(const types::Boolean) noexcept;
        TypeValueCompound(types::Integer) noexcept;
        TypeValueCompound(const Type, ValuePtr) noexcept;
        ~TypeValueCompound() noexcept;
        [[nodiscard]] explicit operator types::NullValue::BaseType() const;
        [[nodiscard]] explicit operator types::String::BaseType() const;
        [[nodiscard]] explicit operator types::Boolean::BaseType() const;
        [[nodiscard]] explicit operator types::Integer::BaseType() const;

    	template <typename T, typename = std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>>>
        TypeValueCompound(T value) noexcept
            : type {Type::INT_TYPE}
            , value {ValuePtr(new Value {types::Integer {static_cast<types::Integer::BaseType>(value)}})} {}
    };
}

#endif