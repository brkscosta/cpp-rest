cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(UploadAi)

# Defina a versão do C++ que você está usando (por exemplo, C++11 ou C++14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/restbed)

# Encontre a biblioteca Restbed
# Adicione seus arquivos de origem
set(SOURCE_FILES main.cpp)

# Crie o executável do seu projeto e vincule com a biblioteca Restbed
add_executable(UploadAi ${SOURCE_FILES})

target_link_libraries(UploadAi PRIVATE restbed-shared)  # Use restbed-static para biblioteca estática
