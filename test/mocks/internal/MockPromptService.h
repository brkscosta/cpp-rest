#include "PromptController.h"
#include "gmock/gmock.h"
#include <gmock/gmock.h>
#include "PromptService.h"

namespace rest::service
{

class MockPrompService : public PromptService
{
    MOCK_METHOD1(addNewPrompt, void(const std::shared_ptr<model::Prompt>&));
    MOCK_METHOD1(getPrompt, void(const std::string&));
};
}  // namespace rest::service