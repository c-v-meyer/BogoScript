/*!
 * \file integer.h
 * \brief Defines the struct \ref bogoscript::typing::integer.
 */

#pragma once

#include <cstdint>
#include <compare>

#include "literal.h"
#include "primitive.h"

namespace bogoscript::typing
{
	/*!
	 * \brief Represents an integer value.
	 */
	struct integer final : literal, primitive
	{
#pragma region types
		/*!
		 * \brief Underlying base type.
		 */
		using base_type = std::int64_t;

		/*!
		 * \brief Another accepted underlying type that shall be cast to \ref base_type upon construction.
		 */
		using possible_literal_type1 = std::int8_t;

		/*!
		 * \copydoc possible_literal_type1
		 */
		using possible_literal_type2 = std::int16_t;

		/*!
		 * \copydoc possible_literal_type1
		 */
		using possible_literal_type3 = std::int32_t;
#pragma endregion

#pragma region members
		/*!
		 * \brief The actual integer value.
		 */
		base_type value;
#pragma endregion

#pragma region methods
		/*!
		 * \brief Constructor from an actual integer value.
		 */
		explicit integer(base_type) noexcept;

		/*!
		 * \brief Cast to an actual integer value.
		 */
		explicit operator base_type() const noexcept;
#pragma endregion

#pragma region friends
		/*!
		 * \brief Comparison operator for two instances of \ref integer.
		 *
		 * \return The comparison result
		 */
		friend std::strong_ordering operator<=>(const integer&, const integer&) noexcept = default;
#pragma endregion
	};
}
