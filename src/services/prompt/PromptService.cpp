#include "PromptService.h"
#include "IPromptDAO.h"
#include <memory>

using namespace rest::service;
using namespace rest::model;

PromptService::PromptService(std::shared_ptr<IPromptDAO>& promptDao)
{
    m_promptDao = promptDao;
}

std::shared_ptr<Prompt> PromptService::getPrompt(std::string& id)
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