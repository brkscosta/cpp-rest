cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(CppRest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" "clang-tidy-<version>")
if (CLANG_TIDY_EXE AND CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=*")
endif ()

option(HAS_GTEST "Build with Google Test support" OFF)

execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_definitions(GIT_COMMIT_HASH="${GIT_COMMIT_HASH}")

include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(src)
if(HAS_GTEST)
  enable_testing()
  add_subdirectory(tests)
endif()

configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)
