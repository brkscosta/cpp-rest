#pragma once
#include "IPromptService.h"
#include <nlohmann/json.hpp>

#include <memory>

namespace rest::model {
class IPromptDAO;
class CreatePromptDto;
}   // namespace rest::model

namespace rest::service {

class PromptService : public IPromptService
{
public:
    PromptService(const std::shared_ptr<model::IPromptDAO>& promptDao);
    ~PromptService() = default;

    void addNewPrompt(const std::shared_ptr<model::CreatePromptDto>& promptDto) override;
    std::string getPrompt(const std::string& id) override;
    std::string getAllPrompts() override;

private:
    std::string toJSON(const nlohmann::json& prompt) const;
    std::shared_ptr<model::IPromptDAO> m_promptDao;
    std::string m_loggerPrefix;
};

}   // namespace rest::service