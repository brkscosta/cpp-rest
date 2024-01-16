#pragma once

#include "ISessionWrapper.h"

namespace rest::service
{
class SessionWrapper : public ISessionWrapper
{
  public:
    SessionWrapper(const std::shared_ptr<restbed::Session>& session);

    std::shared_ptr<IRequestWrapper> getRequest() override;
    std::shared_ptr<restbed::Session> getCurrentSession() override;

    std::shared_ptr<IRequestWrapper> m_requestWrapper;
    std::shared_ptr<restbed::Session> m_session;
};
}  // namespace rest::service