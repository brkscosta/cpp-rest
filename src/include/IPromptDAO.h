#pragma once

#include "IMemoRepo.h"
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
    using PromptMemoRepo = repository::IMemoRepo<std::shared_ptr<Prompt>, std::string>::ManyOrNullResults;

    virtual std::vector<std::shared_ptr<Prompt>> listAllPrompts() = 0;
    virtual std::optional<std::shared_ptr<Prompt>> findPromptById(const std::string& id) = 0;
    virtual void addPrompt(const std::shared_ptr<Prompt>& prompt) = 0;
};

}  // namespace rest::model