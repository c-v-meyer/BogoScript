/*!
 * \file literal.h
 * \brief Defines the struct \ref bogoscript::typing::literal.
 */

#pragma once

#include <compare>

namespace bogoscript::typing
{
	/*!
	 * \brief Superclass for all classes representing actual values.
	 */
	struct literal
	{
#pragma region friends
		/*!
		 * \brief Hypothetical comparison operator for two instances of \ref literal.
		 *
		 * \return Hypothetically returns \c std::strong_ordering::equal.
		 *
		 * \details
		 * This method is never actually used, but it is necessary to make this operator work on all subclasses.
		 */
		[[maybe_unused]] friend std::strong_ordering operator<=>(const literal&, const literal&) noexcept = default;
#pragma endregion
	};
}
