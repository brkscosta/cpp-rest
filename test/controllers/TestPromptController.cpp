#include <nlohmann/json.hpp>
#include "MockIPromptDAO.h"
#include "MockRequest.h"
#include "MockService.h"
#include "MockSession.h"
#include "PromptController.h"
#include "PromptService.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <restbed>
#include <string>

using namespace rest;
using namespace controller;
using namespace model;
using namespace testing;


namespace {
 const nlohmann::json MOCK_JSON_DATA = {
        {"id", "9123-12904123-12"},
        {"title", "My Title"},
        {"template", "My template a-123ndasn"}
    };
}

class TestPromptController : public Test
{
  public:
    TestPromptController();
    ~TestPromptController();

    public:
      std::shared_ptr<controller::PromptController> m_promptController;
};

TestPromptController::TestPromptController()
{}

TestPromptController::~TestPromptController()
{}

TEST_F(TestPromptController, HandlePostResponse_On_AddNewPrompt)
{
    auto mockSession = std::make_shared<restbed::MockSession>();
    auto mockRequest = std::make_shared<restbed::MockRequest>();
    const std::size_t contentLength = 124;

    EXPECT_CALL(*mockSession, get_request()).WillOnce(Return(mockRequest));
    EXPECT_CALL(*mockRequest, get_header("Content-Length", "")).WillOnce(Return(std::to_string(contentLength)));
    EXPECT_CALL(*mockSession, fetch(contentLength, _))
        .WillOnce(Invoke(
            [&mockSession, contentLength](std::size_t length,
                const std::function<void(const std::shared_ptr<restbed::Session>, const restbed::Bytes&)>& callback)
            {
                length = contentLength;
                callback(mockSession, MOCK_JSON_DATA);
            }));

    auto mockService = std::make_shared<restbed::MockService>();
    auto mockPromptDAO = std::make_shared<model::MockIPromptDAO>();
    auto mockPromptService = std::make_shared<rest::service::PromptService>(mockPromptDAO);
    auto promptController = std::make_shared<PromptController>(mockService, mockPromptService);

    promptController->handlePost(mockSession);
}