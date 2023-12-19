#include "PromptController.h"
#include "CRUDService.h"
#include "Prompt.h"
#include "PromptMemoDataAccess.h"
#include "PromptService.h"
#include <algorithm>
#include <memory>
#include <restbed>

using namespace rest::controller;

PromptController::PromptController(
    const std::shared_ptr<restbed::Service>& service,
    const std::shared_ptr<service::PromptService>& promptService
    )
    : m_promptService(promptService)
    , m_crudService(std::make_unique<service::CRUDService<model::Prompt>>(service))
{}

void PromptController::handlePost(const std::shared_ptr<restbed::Session>& session)
{
    std::shared_ptr<model::Prompt> prompt;
    m_crudService->post(session, prompt);

    if(prompt)
    {
        m_promptService->addNewPrompt(prompt);
    }
}

void PromptController::handleGet(const std::shared_ptr<restbed::Session>& session)
{
    auto jsonStringPrompts = m_promptService->getAllPrompts();

    m_crudService->get(session, jsonStringPrompts);
}
