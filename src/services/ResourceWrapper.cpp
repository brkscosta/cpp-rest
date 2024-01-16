#include "ResourceWrapper.h"
#include "SessionWrapper.h"
#include <memory>

using namespace rest::service;

ResourceWrapper::ResourceWrapper()
    : m_resource(std::make_shared<restbed::Resource>())
{}

void ResourceWrapper::setPaths(const std::set<std::string>& paths)
{
    m_resource->set_paths(paths);
}

void ResourceWrapper::setMethodHandler(
    const std::string& method, const std::function<void(const std::shared_ptr<ISessionWrapper>)>& callback)
{
    m_resource->set_method_handler(method, [callback](const std::shared_ptr<restbed::Session>& session)
    {
        const auto sessionWrapper = std::make_shared<SessionWrapper>(session);
        callback(sessionWrapper);
    });
}

std::shared_ptr<restbed::Resource> ResourceWrapper::getResource()
{
    return m_resource;
}