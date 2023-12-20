#include "MockCRUDService.h"
#include "MockIPromptDAO.h"
#include "MockPrompt.h"
#include "MockPromptService.h"
#include "MockRequest.h"
#include "MockService.h"
#include "MockSession.h"
#include "PromptController.h"
#include "PromptService.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <restbed>
#include <string>

using namespace rest;
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
    TestPromptController()
    {
        m_mockService = std::make_shared<restbed::MockService>();
        m_mockPromptDAO = std::make_shared<model::MockIPromptDAO>();
        m_mockPromptService = std::make_shared<service::MockPromptService>(m_mockPromptDAO);
        m_mockPromptCRUDService = std::make_shared<service::MockCRUDService<model::MockPrompt>>(m_mockService);
        m_promptController = std::make_shared<controller::PromptController>(m_mockPromptService, m_mockPromptCRUDService);
    };
    ~TestPromptController() = default;

  protected:
    std::shared_ptr<controller::PromptController> m_promptController;
    std::shared_ptr<restbed::MockService> m_mockService;
    std::shared_ptr<model::MockIPromptDAO> m_mockPromptDAO;
    std::shared_ptr<service::MockPromptService> m_mockPromptService;
    std::shared_ptr<service::MockCRUDService<model::MockPrompt>> m_mockPromptCRUDService;
    std::shared_ptr<restbed::MockSession> m_mockSession;
    std::shared_ptr<restbed::MockRequest> m_mockRequest;
};

TEST_F(TestPromptController, HandlePostResponse_On_AddNewPrompt)
{
    const std::size_t contentLength = 124;
    auto m_mockSession = std::make_shared<restbed::MockSession>();
    auto m_mockRequest = std::make_shared<restbed::MockRequest>();
    m_mockRequest->add_header("Content-Length", std::to_string(contentLength));

    EXPECT_CALL(*m_mockSession, get_request()).WillOnce(Return(m_mockRequest));
    // EXPECT_CALL(*m_mockRequest, get_header("Content-Length", 0)).WillOnce(Return(contentLength));
    EXPECT_CALL(*m_mockSession, fetch(contentLength, _)).WillOnce(Invoke(
    [contentLength, &m_mockSession](std::size_t length, const std::function<void(const std::shared_ptr<restbed::Session>, const restbed::Bytes&)>& callback)
    {
        length = contentLength;
        callback(m_mockSession, MOCK_JSON_DATA);
    }));

    m_promptController->handlePost(m_mockSession);
}