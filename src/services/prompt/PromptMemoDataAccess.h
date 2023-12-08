#pragma once
#include "IPromptDAO.h"
#include <memory>
#include <optional>
#include <vector>

namespace rest::repository
{
template <typename D, typename I>
class IMemoRepo;
}

namespace rest::model
{
class Prompt;
class IPromptDAO;
}  // namespace rest::model

namespace rest::service
{

class PromptMemoDataAccess : public model::IPromptDAO
{
  public:
    PromptMemoDataAccess(const std::shared_ptr<repository::IMemoRepo<model::Prompt, std::string>>& promptRepo);
    ~PromptMemoDataAccess() = default;

    std::vector<std::shared_ptr<model::Prompt>> listAllPrompts() override;
    std::optional<std::shared_ptr<model::Prompt>> findPromptById(std::string& id) override;
    void addPrompt(std::shared_ptr<model::Prompt>& prompt) override;
    std::vector<std::shared_ptr<model::Prompt>> searchByTitle(std::string& title) override;

  private:
    std::shared_ptr<repository::IMemoRepo<model::Prompt, std::string>> m_promptRepo;
    std::vector<std::shared_ptr<model::Prompt>> m_prompts;
};

}  // namespace rest::service
