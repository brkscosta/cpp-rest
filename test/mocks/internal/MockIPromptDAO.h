#include "IPromptDAO.h"
#include "gmock/gmock.h"

namespace rest::model
{
class MockIPromptDAO : public IPromptDAO
{
  public:
    MOCK_METHOD0(listAllPrompts, std::vector<std::shared_ptr<Prompt>>());
    MOCK_METHOD1(findPromptById, std::optional<std::shared_ptr<Prompt>>(const std::string&));
    MOCK_METHOD1(addPrompt, void(const std::shared_ptr<Prompt>&));
};
}  // namespace rest::model
