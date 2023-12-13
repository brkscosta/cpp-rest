#include "MemoRepo.h"
#include "Prompt.h"
#include <cstring>
#include <memory>
#include <string>

using namespace rest::repository;

template <typename D, typename I>
MemoRepo<D, I>::MemoRepo()
{}

template <typename D, typename I>
void MemoRepo<D, I>::add(const D& value)
{
    m_data.push_back(value);
}

template <typename D, typename I>
std::vector<D> MemoRepo<D, I>::findAll()
{
    return m_data;
}

template <typename D, typename I>
void MemoRepo<D, I>::remove(const I& value)
{
    auto it = std::remove_if(m_data.begin(), m_data.end(), [value](const D& element)
    {
        return element->getId() == value;
    });

    m_data.erase(it, m_data.end());
}

template <typename D, typename I>
std::optional<D> MemoRepo<D, I>::findPromptById(const std::string& id)
{
    auto it = std::find_if(m_data.begin(), m_data.end(), [id](const D& element) { return element->getId() == id; });

    if (it != m_data.end())
    {
        return *it;
    }
    else
    {
        return std::nullopt;
    }
}

template <typename D, typename I>
typename IMemoRepo<D, I>::ManyOrNullResults MemoRepo<D, I>::searchByTitle(const std::string& title)
{
    std::vector<D> matchingElements;

    for (const auto& element : m_data)
    {
        if (std::strcmp(element->getTitle().c_str(), title.c_str()) == 0)
        {
            matchingElements.push_back(element);
        }
    }

    if (matchingElements.size() == 1)
    {
        return std::optional<D>(matchingElements[0]);
    }
    else if (matchingElements.size() > 1)
    {
        return matchingElements;
    }
    else
    {
        return std::nullopt;
    }
}

template class rest::repository::MemoRepo<std::shared_ptr<rest::model::Prompt>, std::string>;
