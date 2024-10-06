# CMakeList.txt: CMake-Projekt für "BogoScript". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (BogoScript "example_main.cpp" "include/bogoscript.h" "include/core/runtime_manager.h" "source/core/runtime_manager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BogoScript PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
