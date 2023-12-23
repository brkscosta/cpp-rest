#include "Prompt.h"
#include "gmock/gmock.h"

namespace rest::model
{

class MockPrompt : public Prompt
{
  public:
    MOCK_METHOD0(getId, std::string());
    MOCK_METHOD0(getTitle, std::string());
    MOCK_METHOD0(getTemplate, std::string());
    MOCK_METHOD0(toJson, nlohmann::json());
};

}  // namespace rest::model