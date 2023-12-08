#include "PromptController.h"
#include "CRUDService.h"
#include "Prompt.h"
#include <memory>
#include <restbed>

using namespace rest::controller;

PromptController::PromptController(const std::shared_ptr<restbed::Service>& listener)
    : m_promptCRUDService(std::make_shared<rest::service::CRUDService<rest::model::Prompt>>(listener))
{
}
