#include "SessionWrapper.h"
#include "RequestWrapper.h"
#include "corvusoft/restbed/session.hpp"

#include <memory>

using namespace rest::service;

SessionWrapper::SessionWrapper(const std::shared_ptr<restbed::Session>& session)
    : m_requestWrapper(std::make_shared<RequestWrapper>(session))
    , m_session(session)
{}

std::shared_ptr<IRequestWrapper> SessionWrapper::getRequest()
{
    return m_requestWrapper;
}

std::shared_ptr<restbed::Session> SessionWrapper::getCurrentSession()
{
    return m_session;
}