
#include "PromptMemoDataAccess.h"
#include "IMemoRepo.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <optional>
#include <unordered_set>
#include <vector>

using namespace rest::service;
using namespace rest::model;

PromptMemoDataAccess::PromptMemoDataAccess(
    const std::shared_ptr<repository::IMemoRepo<Prompt, std::string>>& promptRepo)
    : m_promptRepo(promptRepo)
{
}

std::vector<std::shared_ptr<Prompt>> PromptMemoDataAccess::listAllPrompts()
{
    return m_prompts;
}

std::optional<std::shared_ptr<Prompt>> PromptMemoDataAccess::findPromptById(std::string& id)
{
    auto itPrompt = std::find_if(m_prompts.begin(), m_prompts.end(),
        [&id](const std::shared_ptr<Prompt>& prompt) { return prompt->getId() == id; });

    if (itPrompt == m_prompts.end())
    {
        return std::nullopt;
    }

    return std::make_optional(*itPrompt);
}

void PromptMemoDataAccess::addPrompt(std::shared_ptr<Prompt>& prompt)
{
    m_prompts.push_back(prompt);
}

std::vector<std::shared_ptr<Prompt>> PromptMemoDataAccess::searchByTitle(std::string& title)
{
    std::vector<std::shared_ptr<Prompt>> prompts;
    std::unordered_set<std::string> titles;
    for (auto& prompt : m_prompts)
    {
        auto strTitle = prompt->getTitle();
        titles.insert(strTitle);
        if (titles.find(title) != titles.end())
        {
            prompts.push_back(prompt);
        }
    }

    return prompts;
}
