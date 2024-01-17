#include <nlohmann/json.hpp>

#include <string>

namespace rest::model {

class CreatePromptDto
{
public:
    CreatePromptDto(const nlohmann::json& jsonData);
    CreatePromptDto(const std::string& title, const std::string& bodyTemplate);
    ~CreatePromptDto() = default;

    std::string getTitle();
    std::string getTemplate();
    nlohmann::json toJson();
    static std::vector<std::string> validate(const nlohmann::json& jsonData);

private:
    std::string m_title;
    std::string m_template;
};

}   // namespace rest::model