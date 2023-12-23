# services/CMakeLists.txt
set(SOURCE_SERVICES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
  ${SOURCE_SERVICES_DIR}/prompt/PromptMemoDataAccess.cpp
  ${SOURCE_SERVICES_DIR}/prompt/PromptService.cpp
  ${SOURCE_SERVICES_DIR}/CRUDService.cpp
)

include_directories(CppRest PRIVATE
  ${SOURCE_SERVICES_DIR}/prompt
)

target_sources(CppRest PRIVATE ${SOURCE_FILES})
