#include <memory>
#include <restbed>

namespace rest::service
{

template <typename T>
class CRUDService
{
  public:
    CRUDService(const std::shared_ptr<restbed::Service>& listener);
    ~CRUDService() = default;

  public:
    void get(const std::shared_ptr<restbed::Session>& session, const std::string& path);
    void post(const std::shared_ptr<restbed::Session>& session);
    void put(const std::shared_ptr<restbed::Session>& session, const std::string& path);
    void _delete(const std::shared_ptr<restbed::Session>& session, const std::string& path);
    std::string to_json(const T& item);
    T from_json(const std::string& json);

  private:
    std::shared_ptr<restbed::Service> m_listener;
    std::vector<T> m_data;
};
}  // namespace rest::service