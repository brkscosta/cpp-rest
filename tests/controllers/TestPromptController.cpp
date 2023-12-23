#include "MockCRUDService .h"
#include "MockIPromptDAO.h"
#include "MockPrompt.h"
#include "MockPromptService.h"
#include "MockRequest.h"
#include "MockResource.h"
#include "MockService.h"
#include "MockSession.h"
#include "PromptController.h"
#include "PromptService.h"
#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

using namespace rest;
using namespace controller;
using namespace testing;

namespace
{
const nlohmann::json MOCK_JSON_DATA = {{"title", "My Title"}, {"template", "My template"}};
}

class TestPromptController : public Test
{
  public:
    TestPromptController() {};
    ~TestPromptController() override = default;
};

TEST(PromptControllerTest, TestAddNewPrompt)
{
    const auto mockPromptDAO = std::make_shared<model::MockIPromptDAO>();
    const auto mockService = std::make_shared<restbed::MockService>();
    const auto mockSession = std::make_shared<restbed::MockSession>();
    const auto mockPromptService = std::make_shared<service::MockPromptService>(mockPromptDAO);
    const auto mockPrompt = std::make_shared<model::MockPrompt>(MOCK_JSON_DATA);
    const auto mockCRUDService = std::make_shared<service::MockCRUDService<model::Prompt>>();
    const auto mockResource = std::make_shared<restbed::MockResource>();

    EXPECT_CALL(*mockResource, set_method_handler("POST", _))
        .WillOnce(Invoke(
            [&mockSession, &mockCRUDService](
                const std::string& method, const std::function<void(const std::shared_ptr<restbed::Session>)>& callback)
            {
                callback(mockSession);
                std::shared_ptr<model::Prompt> prompt;
                EXPECT_CALL(*mockCRUDService, post(_, prompt)).Times(1);
            }));

    auto promptController = std::make_shared<PromptController>(mockPromptService, mockCRUDService, mockResource);
}