#include "MockCRUDService.h"
#include "MockIPromptDAO.h"
#include "MockPrompt.h"
#include "MockPromptService.h"
#include "MockRequest.h"
#include "MockResource.h"
#include "MockSession.h"
#include "PromptController.h"
#include "PromptService.h"
#include "corvusoft/restbed/session.hpp"
#include <nlohmann/json.hpp>

#include <gtest/gtest.h>

#include <memory>
#include <string>

using namespace rest;
using namespace controller;
using namespace testing;

class TestPromptController : public Test
{
public:
    TestPromptController() {};
    ~TestPromptController() override = default;
};

TEST(PromptControllerTest, TestAddNewPrompt)
{
    const auto mockPromptDAO = std::make_shared<NiceMock<model::MockIPromptDAO>>();
    const auto mockPromptService = std::make_shared<NiceMock<service::MockPromptService>>();
    const auto mockCRUDService = std::make_shared<NiceMock<service::MockCRUDService<model::CreatePromptDto>>>();
    const auto mockResource = std::make_shared<NiceMock<service::MockResource>>();

    EXPECT_CALL(*mockCRUDService, post(_, _)).Times(1);
    EXPECT_CALL(*mockPromptService, addNewPrompt(_)).Times(1);
    EXPECT_CALL(*mockResource, setMethodHandler("POST", _))
          .WillOnce(Invoke(
                [&mockCRUDService, &mockPromptService](
                      const std::string&,
                      const std::function<void(const std::shared_ptr<service::ISessionWrapper>)>& callback)
                {
                    const auto mockSession = std::make_shared<NiceMock<service::MockSession>>();
                    callback(mockSession);
                }));

    EXPECT_CALL(*mockCRUDService, get(_, _)).Times(1);
    EXPECT_CALL(*mockResource, setMethodHandler("GET", _))
          .WillOnce(Invoke(
                [&mockCRUDService](const std::string&,
                                   const std::function<void(const std::shared_ptr<service::ISessionWrapper>)>& callback)
                {
                    const auto mockSession = std::make_shared<NiceMock<service::MockSession>>();
                    const auto mockRequest = std::make_shared<NiceMock<service::MockRequest>>();

                    EXPECT_CALL(*mockSession, getRequest).WillOnce(Return(mockRequest));
                    callback(mockSession);
                }));
    auto promptController = std::make_shared<PromptController>(mockPromptService, mockCRUDService, mockResource);
    ASSERT_TRUE(promptController);
}
