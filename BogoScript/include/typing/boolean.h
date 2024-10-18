/*!
 * \file boolean.h
 * \brief Defines the struct \ref bogoscript::typing::boolean.
 */

#pragma once

#include <compare>

#include "literal.h"
#include "primitive.h"

namespace bogoscript::typing
{
	/*!
	 * \brief Represents a boolean value.
	 */
	struct boolean final : literal, primitive
	{
#pragma region types
		/*!
		 * \brief Underlying base type.
		 */
		using base_type = bool;
#pragma endregion

#pragma region members
		/*!
		 * \brief The actual boolean value.
		 */
		base_type value;
#pragma endregion

#pragma region methods
		/*!
		 * \brief Constructor from an actual boolean value.
		 */
		explicit boolean(base_type) noexcept;

		/*!
		 * \brief Cast to an actual boolean value.
		 */
		explicit operator base_type() const noexcept;
#pragma endregion

#pragma region friends
		/*!
		 * \brief Comparison operator for two instances of \ref boolean.
		 *
		 * \return The comparison result
		 */
		friend std::strong_ordering operator<=>(const boolean&, const boolean&) noexcept = default;
#pragma endregion
	};
}
