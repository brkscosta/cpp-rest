#include "PromptController.h"
#include "CRUDService.h"
#include "Prompt.h"
#include "PromptService.h"
#include <memory>
#include <restbed>

using namespace rest::controller;

PromptController::PromptController(
    const std::shared_ptr<restbed::Service>& service,
    const std::shared_ptr<service::PromptService>& promptService
    )
    : m_promptService(promptService)
    , m_promptCRUDService(std::make_shared<service::CRUDService<model::Prompt>>(service))
{}

void PromptController::handlePost(const std::shared_ptr<restbed::Session>& session)
{
    m_promptCRUDService->post(session);
}

void PromptController::handleGet(const std::shared_ptr<restbed::Session>& session)
{
    m_promptCRUDService->get(session, session->get_request()->get_path());
}
