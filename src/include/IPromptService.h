#pragma once
#include "CreatePromptDto.h"
#include <memory>
#include <string>

namespace rest::service
{
class IPromptService
{
  public:
    virtual void addNewPrompt(const std::shared_ptr<rest::model::CreatePromptDto>& promptDto) = 0;
    virtual std::string getPrompt(const std::string& id) = 0;
    virtual std::string getAllPrompts() = 0;
};
}  // namespace rest::service