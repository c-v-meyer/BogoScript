// runtime_manager.h: Defines the class runtime_manager.

#pragma once

namespace bogoscript::core
{
	class runtime_manager final {
	public:
		static auto& get_instance() noexcept(noexcept(runtime_manager()))
		{
			static runtime_manager instance;
			return instance;
		}

		runtime_manager(runtime_manager const&) = delete;
		runtime_manager(runtime_manager&&) noexcept = delete;
		void operator=(runtime_manager const&) = delete;
		void operator=(runtime_manager&&) noexcept = delete;

	private:
		runtime_manager();
		~runtime_manager();
	};
}
