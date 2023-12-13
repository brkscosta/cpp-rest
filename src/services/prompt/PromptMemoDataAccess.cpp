
#include "PromptMemoDataAccess.h"
#include "IMemoRepo.h"
#include "Prompt.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <optional>
#include <string>
#include <unordered_set>
#include <vector>

using namespace rest;
using namespace service;

PromptMemoDataAccess::PromptMemoDataAccess(const MemoPromptRepo& memoPromptRepo) : m_memoRepo(memoPromptRepo)
{}

std::vector<std::shared_ptr<model::Prompt>> PromptMemoDataAccess::listAllPrompts()
{
    return m_memoRepo->findAll();
}

std::optional<std::shared_ptr<model::Prompt>> PromptMemoDataAccess::findPromptById(std::string& id)
{
    return m_memoRepo->findPromptById(id);
}

void PromptMemoDataAccess::addPrompt(const std::shared_ptr<model::Prompt>& prompt)
{
    m_memoRepo->add(prompt);
}