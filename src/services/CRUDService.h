#pragma once
#include <iostream>
#include <memory>
#include <restbed>
#include <vector>
#include <nlohmann/json.hpp>

namespace rest::service
{
template <typename T>
class CRUDService
{
  public:
    CRUDService(const std::shared_ptr<restbed::Service>& listener);
    ~CRUDService() = default;

    T fromJSON(const std::string& json);
    void get(const std::shared_ptr<restbed::Session>& session, const std::string& jsonData);
    void post(const std::shared_ptr<restbed::Session>& session, std::shared_ptr<T>& item);

  private:
    std::shared_ptr<restbed::Service> m_listener;
};

}  // namespace rest::service
