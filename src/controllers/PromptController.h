#pragma once

#include "CRUDService.h"
#include <memory>

namespace restbed
{
class Service;
class Session;
}  // namespace restbed

namespace rest::model
{
class Prompt;
}

namespace rest::service
{
template <typename T>
class CRUDService;
class PromptService;
}  // namespace rest::service

namespace rest::controller
{

class PromptController
{
  public:
    PromptController(
        const std::shared_ptr<restbed::Service>& service,
        const std::shared_ptr<rest::service::PromptService>& promptService
      );

    ~PromptController() = default;

    void handleGet(const std::shared_ptr<restbed::Session>& session);

    void handlePost(const std::shared_ptr<restbed::Session>& session);

  private:
    std::shared_ptr<rest::service::PromptService> m_promptService;
    std::unique_ptr<rest::service::CRUDService<rest::model::Prompt>> m_crudService;
};

}  // namespace rest::controller
