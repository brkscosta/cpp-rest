#pragma once

#include "ICRUDService.h"
#include <nlohmann/json.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include <restbed>

namespace rest::service {
template<typename T>
class CRUDService : public ICRUDService<T>
{
public:
    CRUDService(const std::shared_ptr<restbed::Service>& listener);
    virtual ~CRUDService() = default;

    void get(const std::shared_ptr<restbed::Session>& session, const std::string& jsonData) override;
    void post(const std::shared_ptr<restbed::Session>& session, std::shared_ptr<T>& item) override;

private:
    std::shared_ptr<restbed::Service> m_listener;
};

}   // namespace rest::service
