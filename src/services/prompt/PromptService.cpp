#include "PromptService.h"
#include "IPromptDAO.h"
#include <algorithm>
#include <iostream>
#include <memory>

using namespace rest;
using namespace service;

PromptService::PromptService(const std::shared_ptr<model::IPromptDAO>& promptDao)
    : m_promptDao(promptDao)
{}

std::shared_ptr<model::Prompt> PromptService::getPrompt(const std::string& id)
{
    auto prompt = m_promptDao->findPromptById(id);

    if (!prompt.has_value())
    {
        return nullptr;
    }

    return prompt.value();
}

void PromptService::addNewPrompt(const std::shared_ptr<model::Prompt>& prompt)
{
    m_promptDao->addPrompt(prompt);
}

std::string PromptService::getAllPrompts()
{
    auto prompts = m_promptDao->listAllPrompts();

    if (prompts.empty())
    {
        std::cout << "No prompts found" << std::endl;
        return {};
    }

    nlohmann::json jsonResult;

    std::for_each(prompts.begin(), prompts.end(), [&jsonResult](const std::shared_ptr<model::Prompt>& prompt)
    {
        nlohmann::json promptJson = prompt->toJson();

        jsonResult.push_back(promptJson);
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
        std::cout << e.what() << std::endl;
    }

    return {};
}