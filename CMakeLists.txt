cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(CppRest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_definitions(GIT_COMMIT_HASH="${GIT_COMMIT_HASH}")

include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(lib/restbed)
add_subdirectory(src)

configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)