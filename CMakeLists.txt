﻿# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

# Aktivieren Sie Hot Reload für MSVC-Compiler, sofern unterstützt.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(NOT DEFINED CMAKE_C_COMPILER)
	message(WARNING "Path to C Compiler is undefined! Assuming C compiler at \"/usr/bin/gcc\".")
	set(CMAKE_C_COMPILER "/usr/bin/gcc")
endif()

if(NOT DEFINED CMAKE_CXX_COMPILER)
	message(WARNING "Path to C++ Compiler is undefined! Assuming C++ compiler at \"/usr/bin/g++\".")
	set(CMAKE_CXX_COMPILER "/usr/bin/g++")
endif()

project ("BogoScript")

# Schließen Sie Unterprojekte ein.
add_subdirectory ("BogoScript")

set_property(TARGET "BogoScript" PROPERTY CXX_STANDARD 20)