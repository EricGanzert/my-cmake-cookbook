cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-05 LANGUAGES CXX)

option(USE_LIBRARY "Compile sources into a library" OFF)

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

include(CMakeDependentOption)

cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
  "USE_LIBRARY" ON
)

cmake_dependent_option(
  MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
  "USE_LIBRARY" ON
)

list(APPEND _sources Message.hpp Message.cpp)

if (USE_LIBRARY)
  message(STATUS "Compile sources into a STATIC library? ${MAKE_STATIC_LIBRARY}")
  message(STATUS "Compile sources into a SHARED library? ${MAKE_SHARED_LIBRARY}")

  if (MAKE_SHARED_LIBRARY)
    add_library(message SHARED ${_sources})

    add_executable(hello-world hello-world.cpp)

    target_link_libraries(hello-world message)
  endif()

  if (MAKE_STATIC_LIBRARY)
    add_library(message STATIC ${_sources})

    add_executable(hello-world hello-world.cpp)

    target_link_libraries(hello-world message)
  endif()
else()
  add_executable(hello-world hello-world.cpp ${_sources})
endif()
