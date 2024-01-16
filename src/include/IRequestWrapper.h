#pragma once

#include <restbed>

namespace rest::service
{
class IRequestWrapper
{
  public:
    virtual std::map<std::string, std::string> getPathParameters(const std::string& name) = 0;
};
}  // namespace rest::service