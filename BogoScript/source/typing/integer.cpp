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
}
