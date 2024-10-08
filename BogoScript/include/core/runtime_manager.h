/*!
 * \file runtime_manager.h
 * \brief Defines the class \ref bogoscript::core::runtime_manager.
 */

#pragma once

namespace bogoscript::core
{
	class runtime_manager final
	{
	public:
		static auto& get_instance() noexcept(noexcept(runtime_manager()))
		{
			static runtime_manager instance;
			return instance;
		}

		runtime_manager(const runtime_manager&) = delete;
		runtime_manager(runtime_manager&&) noexcept = delete;
		void operator=(const runtime_manager&) = delete;
		void operator=(runtime_manager&&) noexcept = delete;

	private:
		runtime_manager();
		~runtime_manager();
	};
}
