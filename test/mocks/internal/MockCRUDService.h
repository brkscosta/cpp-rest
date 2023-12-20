#include "CRUDService.h"
#include "gmock/gmock.h"

namespace rest::service
{

// Mock class for CRUDService
template <typename T>
class MockCRUDService : public CRUDService<T>
{
  public:
    MockCRUDService(const std::shared_ptr<restbed::Service>& listener) : CRUDService<T>(listener)
    {}
    MOCK_METHOD2_T(get, void(const std::shared_ptr<restbed::Session>&, const std::string&));
    MOCK_METHOD2_T(post, void(const std::shared_ptr<restbed::Session>&, T&));
    MOCK_METHOD1_T(fromJSON, T(const std::string& json));
};

}  // namespace rest::service