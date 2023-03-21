#include "TypeValueCompound.hpp"

#include <vector>
#include <string>
#include <memory>
#include <variant>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <typeinfo>

#include "Boolean.hpp"
#include "ErrorValue.hpp"
#include "Integer.hpp"
#include "NullValue.hpp"
#include "String.hpp"
#include "Type.hpp"
#include "Value.hpp"

namespace bogoscript {
    namespace {
        template <typename... Types>
        std::type_info const& getActiveVariantType(const std::variant<Types...>& v) {
            return std::visit([](auto&& x)->decltype(auto) { return typeid(x); }, v);
        }
    }

    types::NullValue nullValue {nullptr};
    types::Boolean trueValue {true};
    types::Boolean falseValue {false};

    ValuePtr TypeValueCompound::errorValuePtr = ValuePtr(new Value {types::ErrorValue {}});
    ValuePtr TypeValueCompound::nullValuePtr = ValuePtr(new Value {nullValue});
    ValuePtr TypeValueCompound::trueValuePtr = ValuePtr(new Value {trueValue});
    ValuePtr TypeValueCompound::falseValuePtr = ValuePtr(new Value {falseValue});

    [[maybe_unused]] TypeValueCompound::TypeValueCompound()
        : type {Type::ERROR_TYPE}
        , value {errorValuePtr} {}

    TypeValueCompound::TypeValueCompound(const TypeValueCompound&) = default;

    TypeValueCompound::TypeValueCompound(TypeValueCompound&& other) noexcept
        : type {std::exchange(other.type, Type::ERROR_TYPE)}
        , value {std::exchange(other.value, nullptr)} {}

    TypeValueCompound& TypeValueCompound::operator=(const TypeValueCompound& other) = default;

    TypeValueCompound& TypeValueCompound::operator=(TypeValueCompound&& other) noexcept {
        if (this != &other) [[likely]] {
            type = std::exchange(other.type, Type::ERROR_TYPE);
            value = std::exchange(other.value, nullptr);
        }
        return *this;
    }

    TypeValueCompound::TypeValueCompound(types::NullValue) noexcept
        : type {Type::NULL_TYPE}
        , value {nullValuePtr} {}

	TypeValueCompound::TypeValueCompound(types::String value) noexcept
        : type {Type::STRING_TYPE}
        , value {ValuePtr(new Value {value})} {}

	TypeValueCompound::TypeValueCompound(types::String::BaseType value) noexcept
        : type {Type::STRING_TYPE}
        , value {ValuePtr(new Value {types::String {std::move(value)}})} {}

    TypeValueCompound::TypeValueCompound(const char* value) noexcept
        : type {Type::STRING_TYPE}
		, value {ValuePtr(new Value {types::String {value}})} {}

	TypeValueCompound::TypeValueCompound(const wchar_t* value) noexcept
        : type {Type::STRING_TYPE}
        , value {ValuePtr(new Value {types::String {value}})} {}

    TypeValueCompound::TypeValueCompound(const types::Boolean value) noexcept
        : type {Type::BOOL_TYPE}
        , value {value ? trueValuePtr : falseValuePtr} {}

    TypeValueCompound::TypeValueCompound(types::Integer value) noexcept
        : type {Type::INT_TYPE}
        , value {ValuePtr(new Value {value})} {}

    TypeValueCompound::TypeValueCompound(const Type type, ValuePtr value) noexcept
        : type {type}, value {std::move(value)} {}

    [[gnu::hot]] TypeValueCompound::~TypeValueCompound() noexcept {
        type = Type::ERROR_TYPE;
        value = nullptr;
    }

    [[nodiscard]] TypeValueCompound::operator types::NullValue::BaseType() const {
        if (static const auto typeHash {typeid(types::NullValue).hash_code()}; getActiveVariantType(*value).hash_code() != typeHash) [[unlikely]]
            throw "Tried to use a non-null value in a null context!";
        return std::get<types::NullValue>(*value);
    }

    [[nodiscard]] TypeValueCompound::operator types::String::BaseType() const {
        if (static const auto typeHash {typeid(types::String).hash_code()}; getActiveVariantType(*value).hash_code() != typeHash) [[unlikely]]
            throw "Tried to use a non-string value in a string context!";
        return std::get<types::String>(*value);
    }

    [[nodiscard]] TypeValueCompound::operator types::Boolean::BaseType() const {
        if (static const auto typeHash {typeid(types::Boolean).hash_code()}; getActiveVariantType(*value).hash_code() != typeHash) [[unlikely]]
            throw "Tried to use a non-bool value in a bool context!";
        return std::get<types::Boolean>(*value).value;
    }

    [[nodiscard]] TypeValueCompound::operator types::Integer::BaseType() const {
        if (static const auto typeHash {typeid(types::Integer).hash_code()}; getActiveVariantType(*value).hash_code() != typeHash) [[unlikely]]
            throw "Tried to use a non-int value in an int context!";
        return std::get<types::Integer>(*value);
    }
}