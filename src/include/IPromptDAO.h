#pragma once

#include "Prompt.h"
#include <cstdlib>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace rest::model
{
class IPromptDAO
{
  public:
    virtual std::vector<std::shared_ptr<Prompt>> listAllPrompts() = 0;
    virtual std::optional<std::shared_ptr<Prompt>> findPromptById(std::string& id) = 0;
    virtual void addPrompt(std::shared_ptr<Prompt>& prompt) = 0;
    virtual std::vector<std::shared_ptr<Prompt>> searchByTitle(std::string& title) = 0;
};

}  // namespace rest::model