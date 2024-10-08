#include "../../include/typing/integer.h"

namespace bogoscript::typing
{
	integer::integer(const base_type value) noexcept
		: value(value)
	{
	}

	integer::operator base_type() const noexcept
	{
		return value;
	}

	/*
	std::strong_ordering operator<=>(const integer& lhs, const integer& rhs) noexcept {
		if (lhs.value == rhs.value)
			return std::strong_ordering::equal;
		else if (lhs.value < rhs.value)
			return std::strong_ordering::less;
		return std::strong_ordering::greater;
	}
	*/
}
