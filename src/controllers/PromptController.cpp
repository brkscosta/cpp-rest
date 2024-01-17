#include "PromptController.h"

#include "CRUDService.h"
#include "IPromptService.h"
#include "IResourceWrapper.h"
#include "Paths.h"
#include "PromptMemoDataAccess.h"

#include <functional>
#include <memory>
#include <regex>

using namespace rest::controller;

PromptController::PromptController(
      const std::shared_ptr<service::IPromptService>& promptService,
      const std::shared_ptr<service::ICRUDService<model::CreatePromptDto>>& promptCrudService,
      const std::shared_ptr<service::IResourceWrapper>& resource)
    : m_promptService(promptService)
    , m_crudService(promptCrudService)
    , m_resourceWrapper(resource)
    , m_loggerPrefix("PromptController::")
{
    m_resourceWrapper->setPaths(rest::paths::PROMPTS);

    m_resourceWrapper->setMethodHandler("POST",
                                        std::bind(&PromptController::onAddNewPrompt, this, std::placeholders::_1));
    m_resourceWrapper->setMethodHandler("GET", std::bind(&PromptController::onGet, this, std::placeholders::_1));
}

void PromptController::onAddNewPrompt(const std::shared_ptr<service::ISessionWrapper>& sessionWrapper)
{
    std::shared_ptr<model::CreatePromptDto> promptDto;
    m_crudService->post(sessionWrapper->getCurrentSession(), promptDto);

    m_promptService->addNewPrompt(promptDto);
}

void PromptController::onGet(const std::shared_ptr<service::ISessionWrapper>& sessionWrapper)
{
    const auto request = sessionWrapper->getRequest();
    const auto hasPathParameters = !request->getPathParameters("").empty();

    if (hasPathParameters)
    {
        onGetPrompt(sessionWrapper);
    }
    else
    {
        onGetAllPrompts(sessionWrapper);
    }
}

void PromptController::onGetAllPrompts(const std::shared_ptr<service::ISessionWrapper>& sessionWrapper)
{
    auto jsonStringPrompts = m_promptService->getAllPrompts();

    m_crudService->get(sessionWrapper->getCurrentSession(), jsonStringPrompts);
}

void PromptController::onGetPrompt(const std::shared_ptr<service::ISessionWrapper>& sessionWrapper)
{
    const auto pathParameters = sessionWrapper->getRequest()->getPathParameters("id");

    std::string id = pathParameters.at("id");
    auto prompt = m_promptService->getPrompt(id);

    m_crudService->get(sessionWrapper->getCurrentSession(), prompt);
}
