#ifndef BOGOSCRIPT_VALUE_HPP
#define BOGOSCRIPT_VALUE_HPP

#include <memory>
#include <variant>

#include "ErrorValue.hpp"
#include "NullValue.hpp"
#include "String.hpp"
#include "Boolean.hpp"
#include "Integer.hpp"

namespace bogoscript {
	using Value = std::variant<types::ErrorValue, types::NullValue, types::String, types::Boolean, types::Integer>;
	using ValuePtr = std::shared_ptr<Value>;
}

#endif