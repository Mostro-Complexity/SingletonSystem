set(PROJECT_NAME test_lib_1)

file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)
file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

if(BUILD_SINGLETON_SYSTEM_SHARED_LIBS)
  message("Build ${PROJECT_NAME} Shared Libs")
  add_library(${PROJECT_NAME} SHARED ${sources} ${headers})

  target_compile_definitions(
    ${PROJECT_NAME} PUBLIC ${Qt5Widgets_DEFINITIONS} PRIVATE TEST_LIB_1_EXPORT
  )
else()
  message("Build ${PROJECT_NAME} Static Libs")
  add_library(${PROJECT_NAME} STATIC ${sources} ${headers})
endif()

target_sources(${PROJECT_NAME} PRIVATE ${sources})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
)

target_link_libraries(
  ${PROJECT_NAME} PUBLIC common
)

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /wd4127 /EHsc>
          $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>
          $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra>
)
