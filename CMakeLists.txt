cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(UploadAi)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/restbed)
add_subdirectory(src)
