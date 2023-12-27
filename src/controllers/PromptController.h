#pragma once

#include "IRestController.h"
#include <memory>
#include <restbed>
#include <string>

namespace rest::model
{
class CreatePromptDto;
}

namespace rest::service
{
template <typename T>
class ICRUDService;
class PromptService;
}  // namespace rest::service

namespace rest::controller
{

class PromptController : public IRestController
{
  public:
    PromptController(
        const std::shared_ptr<service::PromptService>& promptService,
        const std::shared_ptr<service::ICRUDService<model::CreatePromptDto>>& promptCrudService,
        const std::shared_ptr<restbed::Resource>& resource
      );
    ~PromptController() override = default;

    std::shared_ptr<restbed::Resource> getResource() override;

  private:
    void onGetAllPrompts(const std::shared_ptr<restbed::Session>& session);
    void onAddNewPrompt(const std::shared_ptr<restbed::Session>& session);
    void onGetPrompt(const std::shared_ptr<restbed::Session>& session);
    void onGet(const std::shared_ptr<restbed::Session>& session);

    std::shared_ptr<service::PromptService> m_promptService;
    std::shared_ptr<service::ICRUDService<model::CreatePromptDto>> m_crudService;
    std::shared_ptr<restbed::Resource> m_resource;
    std::string m_loggerPrefix;
};

}  // namespace rest::controller
