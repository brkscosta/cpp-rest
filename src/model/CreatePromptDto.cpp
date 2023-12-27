#include "CreatePromptDto.h"
#include <string>

using namespace rest::model;

CreatePromptDto::CreatePromptDto(const nlohmann::json& jsonData)
    : m_title(jsonData.value("title", ""))
    , m_template(jsonData.value("template", ""))
{}

CreatePromptDto::CreatePromptDto(const std::string& title, const std::string& bodyTemplate)
    : m_title(title)
    , m_template(bodyTemplate)
{}

std::string CreatePromptDto::getTemplate()
{
    return m_template;
}

std::string CreatePromptDto::getTitle()
{
    return m_title;
}

std::vector<std::string> CreatePromptDto::validate(const nlohmann::json& jsonData)
{
    std::vector<std::string> missingFields;

    if (!jsonData.contains("title") || jsonData.value("title", "").empty())
    {
        missingFields.push_back("title");
    }

    if (!jsonData.contains("template") || jsonData.value("template", "").empty())
    {
        missingFields.push_back("template");
    }

    return missingFields;
}

nlohmann::json CreatePromptDto::toJson()
{
    return {
        {"title", m_title},
        {"template", m_template}
    };
}
