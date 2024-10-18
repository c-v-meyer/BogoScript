#include "../../include/typing/boolean.h"

namespace bogoscript::typing
{
	boolean::boolean(const base_type value) noexcept
		: value(value)
	{
	}

	boolean::operator base_type() const noexcept
	{
		return value;
	}
}
