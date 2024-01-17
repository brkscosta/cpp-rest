#pragma once

#include "IResourceWrapper.h"

namespace rest::service {
class ResourceWrapper : public IResourceWrapper
{
public:
    ResourceWrapper();
    ~ResourceWrapper() override = default;

    void setPaths(const std::set<std::string>& paths) override;
    void setMethodHandler(const std::string& method,
                          const std::function<void(const std::shared_ptr<ISessionWrapper>)>& callback) override;
    std::shared_ptr<restbed::Resource> getResource();

private:
    std::shared_ptr<restbed::Resource> m_resource;
};

}   // namespace rest::service
