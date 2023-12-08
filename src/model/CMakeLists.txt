set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_DIR}/Prompt.cpp
)

target_sources(UploadAi PRIVATE ${SOURCE_FILES})

target_include_directories(UploadAi PRIVATE
  ${SOURCE_DIR}
)