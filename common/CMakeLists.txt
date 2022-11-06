set(PROJECT_NAME common)

file(
  GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)
file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
list(APPEND all_files ${headers} ${sources})

if(BUILD_SINGLETON_SYSTEM_SHARED_LIBS)
  message("Build ${PROJECT_NAME} Shared Libs")
  add_library(${PROJECT_NAME} SHARED ${all_files})

  target_compile_definitions(
    ${PROJECT_NAME} PUBLIC ${Qt5Widgets_DEFINITIONS} PRIVATE COMMON_EXPORT
  )
else()
  message("Build ${PROJECT_NAME} Static Libs")
  add_library(${PROJECT_NAME} STATIC ${all_files})
endif()

target_sources(${PROJECT_NAME} PRIVATE ${sources})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake COMPONENT ${PROJECT_NAME}
)

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /wd4127 /EHsc>
          $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>
          $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra>
)
