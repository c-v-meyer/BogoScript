// example_main.cpp: Example main file.

#include "include/bogoscript.h"
#include "include/core/runtime_manager.h"

int main()
{
	bogoscript::core::runtime_manager::get_instance();
	return 0;
}
