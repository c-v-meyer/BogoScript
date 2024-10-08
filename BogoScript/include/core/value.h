/*!
 * \file value.h
 * \brief Defines using-declarations surrounding the generalization of a value.
 */

#pragma once

#include <variant>
#include <memory>

#include "../typing/integer.h"

namespace bogoscript::core
{
	/*!
	 * \brief Generalization of the concept of a value.
	 *
	 * \details
	 * \c std::variant that can hold values of all possible types.
	 */
	using value = std::variant<typing::integer>;

	/*!
	 * \brief Smart pointer to a value.
	 *
	 * \details
	 * Smart pointer to a \ref bogoscript::core::value. Required to avoid problems with recursive types.
	 */
	using value_pointer = std::shared_ptr<value>;
}
