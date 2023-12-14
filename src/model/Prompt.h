#pragma once
#include <string>

namespace rest::model
{
class Prompt
{
  public:
    Prompt();
    ~Prompt() = default;

    void setId(const std::string& id);
    std::string getId();
    void setTitle(const std::string& title);
    std::string getTitle();
    void setTemplate(const std::string& value);
    std::string getTemplate();

  private:
    std::string m_id;
    std::string m_title;
    std::string m_template;
};

}  // namespace rest::model