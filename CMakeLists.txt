cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(CppRest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(lib/restbed)
add_subdirectory(src)
