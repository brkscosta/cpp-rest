#pragma once

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>

namespace rest::model
{
class Prompt
{
  public:
    Prompt(const std::string& title, const std::string& bodyTemplate);
    ~Prompt() = default;

    std::string getId();
    std::string getTitle();
    std::string getTemplate();

  private:
    std::string m_id;
    std::string m_title;
    std::string m_template;
};

}  // namespace rest::model