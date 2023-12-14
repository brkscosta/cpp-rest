#include "Prompt.h"

using namespace rest::model;

Prompt::Prompt()
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

void Prompt::setId(const std::string& id)
{
    m_id = id;
}

void Prompt::setTemplate(const std::string& value)
{
    m_template = value;
}

void Prompt::setTitle(const std::string& title)
{
    m_title = title;
}