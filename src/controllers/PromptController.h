#pragma once
#include <memory>

namespace restbed
{
class Service;
}

namespace rest::model
{
class Prompt;
}

namespace rest::service
{
template <typename T>
class CRUDService;
}  // namespace rest::service

namespace rest::controller
{
class PromptController
{
  public:
    PromptController(const std::shared_ptr<restbed::Service>& listener);
    ~PromptController() = default;

  private:
    std::shared_ptr<service::CRUDService<model::Prompt>> m_promptCRUDService;
};

};  // namespace rest::controller
