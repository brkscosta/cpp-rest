# services/CMakeLists.txt
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_DIR}/CRUDService.cpp
  ${SOURCE_DIR}/prompt/PromptMemoDataAccess.cpp
  ${SOURCE_DIR}/prompt/PromptService.cpp
)

target_sources(UploadAi PRIVATE ${SOURCE_FILES})

target_include_directories(UploadAi PRIVATE ${SOURCE_DIR})

target_include_directories(UploadAi PRIVATE ${SOURCE_DIR}/prompt)
