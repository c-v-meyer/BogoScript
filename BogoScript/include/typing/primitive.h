/*!
 * \file primitive.h
 * \brief Defines the struct \ref bogoscript::typing::primitive.
 */

#pragma once

#include <compare>

namespace bogoscript::typing
{
	/*!
	 * \brief Superclass for all classes representing primitive (i.e. non-aggregate) values.
	 */
	struct primitive
	{
#pragma region friends
		/*!
		 * \brief Hypothetical comparison operator for two instances of \ref primitive.
		 *
		 * \return Hypothetically returns \c std::strong_ordering::equal.
		 *
		 * \details
		 * This method is never actually used, but it is necessary to make this operator work on all subclasses.
		 */
		[[maybe_unused]] friend std::strong_ordering operator<=>(const primitive&, const primitive&) noexcept = default;
#pragma endregion
	};
}
