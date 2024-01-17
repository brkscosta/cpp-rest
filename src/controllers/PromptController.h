#pragma once

#include <memory>
#include <string>

#include <restbed>

namespace rest::model {
class CreatePromptDto;
}

namespace rest::service {
template<typename T>
class ICRUDService;
class PromptService;
class IResourceWrapper;
class IPromptService;
class ISessionWrapper;
}   // namespace rest::service

namespace rest::controller {

class PromptController
{
public:
    PromptController(const std::shared_ptr<service::IPromptService>& promptService,
                     const std::shared_ptr<service::ICRUDService<model::CreatePromptDto>>& promptCrudService,
                     const std::shared_ptr<service::IResourceWrapper>& resource);
    ~PromptController() = default;

private:
    void onGetAllPrompts(const std::shared_ptr<service::ISessionWrapper>& session);
    void onAddNewPrompt(const std::shared_ptr<service::ISessionWrapper>& session);
    void onGetPrompt(const std::shared_ptr<service::ISessionWrapper>& session);
    void onGet(const std::shared_ptr<service::ISessionWrapper>& session);

    std::shared_ptr<service::IPromptService> m_promptService;
    std::shared_ptr<service::ICRUDService<model::CreatePromptDto>> m_crudService;
    std::shared_ptr<service::IResourceWrapper> m_resourceWrapper;
    std::string m_loggerPrefix;
};

}   // namespace rest::controller
