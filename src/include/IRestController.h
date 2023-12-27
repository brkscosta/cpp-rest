#pragma once

#include <memory>
#include <restbed>

namespace rest::controller
{
class IRestController
{
  public:
    virtual ~IRestController() = default;
    virtual std::shared_ptr<restbed::Resource> getResource() = 0;
};

}  // namespace rest::controller