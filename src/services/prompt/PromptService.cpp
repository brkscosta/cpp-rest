#include "PromptService.h"

#include "IPromptDAO.h"
#include "Prompt.h"

#include <algorithm>
#include <iostream>
#include <memory>

using namespace rest;
using namespace service;

PromptService::PromptService(const std::shared_ptr<model::IPromptDAO>& promptDao)
    : m_promptDao(promptDao)
    , m_loggerPrefix("PromptService::")
{}

std::string PromptService::getPrompt(const std::string& id)
{
    auto prompt = m_promptDao->findPromptById(id);

    if (!prompt.has_value())
    {
        return nullptr;
    }

    auto promptValue = prompt.value();
    auto promptDto = std::make_shared<model::CreatePromptDto>(promptValue->getTitle(), promptValue->getTemplate());
    return toJSON(promptDto->toJson());
}

void PromptService::addNewPrompt(const std::shared_ptr<model::CreatePromptDto>& promptDto)
{
    if (!promptDto)
    {
        std::cout << m_loggerPrefix << "addNewPrompt: PromptDto is not valid" << std::endl;
        return;
    }

    auto entity = std::make_shared<model::Prompt>(promptDto->getTitle(), promptDto->getTemplate());
    std::cout << m_loggerPrefix << "addNewPrompt: PromptId: " << entity->getId() << std::endl;
    m_promptDao->addPrompt(entity);
}

std::string PromptService::getAllPrompts()
{
    auto prompts = m_promptDao->listAllPrompts();

    if (prompts.empty())
    {
        std::cout << m_loggerPrefix << "getAllPrompts: No prompts found" << std::endl;
        return {};
    }

    nlohmann::json jsonResult;

    std::for_each(prompts.begin(), prompts.end(), [&jsonResult](const std::shared_ptr<model::Prompt>& prompt)
    {
        if (prompt)
        {
            auto promptDto = std::make_shared<model::CreatePromptDto>(prompt->getTitle(),
                                                                    prompt->getTemplate());
            nlohmann::json promptJson = promptDto->toJson();
            jsonResult.push_back(promptJson);
        }
    });

    return toJSON(jsonResult);
}

std::string PromptService::toJSON(const nlohmann::json& prompt) const
{
    try
    {
        return prompt.dump(2);
    }
    catch (const nlohmann::json::type_error& e)
    {
        std::cout << m_loggerPrefix << "toJSON: " << e.what() << std::endl;
    }

    return {};
}
