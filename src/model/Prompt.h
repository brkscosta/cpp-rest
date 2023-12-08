#pragma once
#include <string>

namespace rest::model
{
class Prompt
{
  public:
    Prompt();
    ~Prompt() = default;

    void setId(std::string& id);
    std::string getId();
    void setTitle(std::string& title);
    std::string getTitle();
    void setTemplate(std::string& value);
    std::string getTemplate();

  private:
    std::string m_id;
    std::string m_title;
    std::string m_template;
};

}  // namespace rest::model