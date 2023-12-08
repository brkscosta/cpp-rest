# src/CMakeLists.txt
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_DIR}/main.cpp
)

add_executable(UploadAi ${SOURCE_FILES})

target_link_directories(UploadAi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib/restbed)
target_link_libraries(UploadAi PRIVATE restbed-shared)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(model)
add_subdirectory(repositories)
add_subdirectory(controllers)
add_subdirectory(services)
