#include "PromptService.h"
#include "IPromptDAO.h"
#include <algorithm>
#include <memory>

using namespace rest;
using namespace service;

PromptService::PromptService(const std::shared_ptr<model::IPromptDAO>& promptDao)
    : m_promptDao(promptDao)
{}

std::shared_ptr<model::Prompt> PromptService::getPrompt(std::string& id)
{
    auto prompt = m_promptDao->findPromptById(id);

    if (!prompt.has_value())
    {
        return nullptr;
    }

    return prompt.value();
}

void PromptService::addNewPrompt(std::shared_ptr<model::Prompt>& prompt)
{
    m_promptDao->addPrompt(prompt);
}