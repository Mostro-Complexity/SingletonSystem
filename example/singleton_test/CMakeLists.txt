set(PROJECT_NAME singleton_test)

add_subdirectory(test_lib_1)
add_subdirectory(test_lib_2)

add_executable (${PROJECT_NAME} "main.cpp" "singleton_system.h")

target_sources(${PROJECT_NAME} PRIVATE "main.cpp")

target_link_libraries(
  ${PROJECT_NAME} PUBLIC common test_lib_1 test_lib_2
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()
