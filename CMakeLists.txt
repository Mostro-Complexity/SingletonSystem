cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME SingletonSystem)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

add_compile_options(
  $<$<AND:$<NOT:$<COMPILE_LANGUAGE:CUDA>>,$<OR:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>>:/MP8>
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/install")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPACK_GENERATOR "ZIP")
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)

option(BUILD_DEBUG_POSTFIX_D "Append d suffix to debug libraries" ON)
option(BUILD_SHARED_LIBS "Build shared libs" OFF)
option(BUILD_SINGLETON_SYSTEM_SHARED_LIBS "Build smart camera shared libs" ON)

include(fetch/xrepo)
include(CPack)

# 包含子项目。
add_subdirectory (common)
add_subdirectory (example)
