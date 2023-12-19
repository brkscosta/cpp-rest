#pragma once
#include <memory>

namespace rest::model
{
class IPromptDAO;
class Prompt;
}  // namespace rest::model

namespace rest::service
{

class PromptService
{
  public:
    PromptService(const std::shared_ptr<model::IPromptDAO>& promptDao);
    ~PromptService() = default;

    void addNewPrompt(const std::shared_ptr<model::Prompt>& prompt);
    std::shared_ptr<model::Prompt> getPrompt(const std::string& id);

  private:
    std::shared_ptr<model::IPromptDAO> m_promptDao;
};

}  // namespace rest::service