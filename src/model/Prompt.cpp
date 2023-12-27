#include "Prompt.h"

using namespace rest::model;

Prompt::Prompt(const std::string& title, const std::string& bodyTemplate)
    : m_id(boost::lexical_cast<std::string>(boost::uuids::random_generator()()))
    , m_title(title)
    , m_template(bodyTemplate)
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
