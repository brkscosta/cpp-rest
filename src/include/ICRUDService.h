#include <restbed>

namespace rest::service
{
template <typename T>
class ICRUDService
{
  public:
    virtual void get(const std::shared_ptr<restbed::Session>& session, const std::string& jsonData) = 0;
    virtual void post(const std::shared_ptr<restbed::Session>& session, std::shared_ptr<T>& item) = 0;
};
}  // namespace rest::service