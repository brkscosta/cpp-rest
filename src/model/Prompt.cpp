#include "Prompt.h"

using namespace rest::model;

Prompt::Prompt(const nlohmann::json& jsonData)
    : m_id(jsonData.value("id", boost::lexical_cast<std::string>(boost::uuids::random_generator()())))
    , m_title(jsonData.value("title", ""))
    , m_template(jsonData.value("template", ""))
{}

std::string Prompt::getId()
{
    return m_id;
}

std::string Prompt::getTitle()
{
    return m_title;
}

std::string Prompt::getTemplate()
{
    return m_template;
}
