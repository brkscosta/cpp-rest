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
    PromptService(std::shared_ptr<model::IPromptDAO>& promptDao);
    ~PromptService() = default;

    void addNewPrompt(std::shared_ptr<model::Prompt>& prompt);
    std::shared_ptr<model::Prompt> getPrompt(std::string& id);

  private:
    std::shared_ptr<rest::model::IPromptDAO> m_promptDao;
};

}  // namespace rest::service