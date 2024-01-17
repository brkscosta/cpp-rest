#pragma once

#include "IRequestWrapper.h"

#include <memory>

#include <restbed>

namespace rest::service {
class RequestWrapper : public IRequestWrapper
{
public:
    RequestWrapper(const std::shared_ptr<restbed::Session>& session);

    std::map<std::string, std::string> getPathParameters(const std::string& name) override;

private:
    const std::shared_ptr<restbed::Session>& m_session;
};
}   // namespace rest::service