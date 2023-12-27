include_directories(
  ${CMAKE_SOURCE_DIR}/src/controllers
  ${CMAKE_SOURCE_DIR}/src/services
  ${CMAKE_SOURCE_DIR}/src/services/prompt
  ${CMAKE_SOURCE_DIR}/src/include
  ${CMAKE_SOURCE_DIR}/src/model
  ${CMAKE_SOURCE_DIR}/src/repositories
  ${CMAKE_CURRENT_SOURCE_DIR}/mocks/external
  ${CMAKE_CURRENT_SOURCE_DIR}/mocks/internal
  ${CONAN_INCLUDE_DIRS}
)

SET(GTEST_SRCS
  MainTest.cpp
  
  # Target test files
  controllers/TestPromptController.cpp

  # Files depedency
  ${CMAKE_SOURCE_DIR}/src/controllers/PromptController.cpp
  ${CMAKE_SOURCE_DIR}/src/model/Prompt.cpp
  ${CMAKE_SOURCE_DIR}/src/model/CreatePromptDto.cpp
  ${CMAKE_SOURCE_DIR}/src/services/prompt/PromptService.cpp
)

add_executable(CppRestTest ${GTEST_SRCS})

add_test(CppRestTest CppRestTest)

add_custom_target(run_tests COMMAND CppRestTest)

target_link_libraries(CppRestTest ${CONAN_LIBS})