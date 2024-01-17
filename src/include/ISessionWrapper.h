#pragma once

#include "IRequestWrapper.h"

#include <restbed>

namespace rest::service {
class ISessionWrapper
{
public:
    virtual std::shared_ptr<IRequestWrapper> getRequest() = 0;
    virtual std::shared_ptr<restbed::Session> getCurrentSession() = 0;
};
}   // namespace rest::service