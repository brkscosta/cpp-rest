#include "IResourceWrapper.h"
#include <gmock/gmock.h>

namespace rest::service
{
class MockResource : public IResourceWrapper
{
  public:
    MOCK_METHOD1(setPaths, void(const std::set<std::string>&));
    MOCK_METHOD2(setMethodHandler,
        void(const std::string&, const std::function<void(const std::shared_ptr<service::ISessionWrapper>)>&));
};

}  // namespace rest::service
