# controllers/CMakeLists.txt
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_DIR}/PromptController.cpp
)

target_sources(CppRest PRIVATE ${SOURCE_FILES})

target_include_directories(CppRest PRIVATE ${SOURCE_DIR})