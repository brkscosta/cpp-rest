#pragma once
#include "IMemoRepo.h"
#include "IPromptDAO.h"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace rest::repository
{
template <typename D, typename I>
class IMemoRepo;
}  // namespace rest::repository

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
    using MemoPromptRepo = std::shared_ptr<repository::IMemoRepo<std::shared_ptr<model::Prompt>, std::string>>;
    PromptMemoDataAccess(const MemoPromptRepo& memoPromptRepo);
    ~PromptMemoDataAccess() = default;

    std::vector<std::shared_ptr<model::Prompt>> listAllPrompts() override;
    std::optional<std::shared_ptr<model::Prompt>> findPromptById(const std::string& id) override;
    void addPrompt(const std::shared_ptr<model::Prompt>& prompt) override;

  private:
    MemoPromptRepo m_memoRepo;
};

}  // namespace rest::service
