#include "PromptService.h"
#include "gmock/gmock.h"

namespace rest::service
{

class MockPromptService : public PromptService
{
  public:
    MockPromptService(const std::shared_ptr<model::IPromptDAO>& promptDao) : PromptService(promptDao) {};
    MOCK_METHOD1(addNewPrompt, void(const std::shared_ptr<model::Prompt>&));
    MOCK_METHOD1(getPrompt, void(const std::string&));
    MOCK_METHOD0(getAllPrompts, std::string());
};
}  // namespace rest::service