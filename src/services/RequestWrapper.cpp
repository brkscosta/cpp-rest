#include "RequestWrapper.h"
#include "corvusoft/restbed/request.hpp"
#include <memory>

using namespace rest::service;

RequestWrapper::RequestWrapper(const std::shared_ptr<restbed::Session>& session)
  : m_session(session)
{}

std::map<std::string, std::string> RequestWrapper::getPathParameters(const std::string& name)
{

  if (!m_session) {
    return {};
  }

  return m_session->get_request()->get_path_parameters(name);
}