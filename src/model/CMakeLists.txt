set(SOURCE_MODEL_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_MODEL_DIR}/Prompt.cpp
)

target_sources(CppRest PRIVATE ${SOURCE_FILES})

target_include_directories(CppRest PRIVATE
  ${SOURCE_MODEL_DIR}
)