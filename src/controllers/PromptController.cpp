#include "PromptController.h"
#include "CRUDService.h"
#include "Paths.h"
#include "Prompt.h"
#include "PromptMemoDataAccess.h"
#include "PromptService.h"
#include <functional>
#include <memory>

using namespace rest::controller;

PromptController::PromptController(
    const std::shared_ptr<service::PromptService>& promptService,
    const std::shared_ptr<service::ICRUDService<model::Prompt>>& promptCrudService,
    const std::shared_ptr<restbed::Resource>& resource
    )
    : m_promptService(promptService)
    , m_crudService(promptCrudService)
    , m_resource(resource)
{
    m_resource->set_paths(rest::paths::PROMPTS);

    m_resource->set_method_handler("POST", std::bind(&PromptController::onAddNewPrompt, this, std::placeholders::_1));
    m_resource->set_method_handler("GET", std::bind(&PromptController::onGetAllPrompts, this, std::placeholders::_1));
}

std::shared_ptr<restbed::Resource> PromptController::getResource()
{
    return m_resource;
}

void PromptController::onAddNewPrompt(const std::shared_ptr<restbed::Session>& session)
{
    std::shared_ptr<model::Prompt> prompt;
    m_crudService->post(session, prompt);

    if(prompt)
    {
        std::cout << prompt->toJson() << std::endl;
        m_promptService->addNewPrompt(prompt);
    }
}

void PromptController::onGetAllPrompts(const std::shared_ptr<restbed::Session>& session)
{
    auto jsonStringPrompts = m_promptService->getAllPrompts();

    m_crudService->get(session, jsonStringPrompts);
}
