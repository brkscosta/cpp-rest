set(SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(CppRest ${SOURCE_FILES})
target_compile_options(CppRest PRIVATE -g)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(model)
add_subdirectory(repositories)
add_subdirectory(controllers)
add_subdirectory(services)

target_link_libraries(CppRest PRIVATE ${CONAN_LIBS})
