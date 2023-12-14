# services/CMakeLists.txt
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_DIR}/prompt/PromptMemoDataAccess.cpp
  ${SOURCE_DIR}/prompt/PromptService.cpp
  ${SOURCE_DIR}/CRUDService.cpp
)

target_sources(CppRest PRIVATE ${SOURCE_FILES})

target_include_directories(CppRest PRIVATE
  ${SOURCE_DIR}
  ${SOURCE_DIR}/prompt
)
