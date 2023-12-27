set(SOURCE_MODEL_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_MODEL_DIR}/Prompt.cpp
  ${SOURCE_MODEL_DIR}/CreatePromptDto.cpp
)

target_sources(CppRest PRIVATE ${SOURCE_FILES})

include_directories(CppRest PRIVATE
  ${SOURCE_MODEL_DIR}
)