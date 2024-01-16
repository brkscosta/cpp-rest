#pragma once

#include "IPromptService.h"
#include <gmock/gmock.h>

namespace rest::service
{
class MockPromptService : public IPromptService
{
  public:
    MOCK_METHOD1(addNewPrompt, void(const std::shared_ptr<rest::model::CreatePromptDto>&));
    MOCK_METHOD1(getPrompt, std::string(const std::string&));
    MOCK_METHOD0(getAllPrompts, std::string());
};
}  // namespace rest::service