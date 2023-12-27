#include "PromptController.h"
#include "CRUDService.h"
#include "CreatePromptDto.h"
#include "Paths.h"
#include "PromptMemoDataAccess.h"
#include "PromptService.h"
#include "corvusoft/restbed/rule.hpp"
#include <functional>
#include <memory>
#include <regex>

using namespace rest::controller;

PromptController::PromptController(
    const std::shared_ptr<service::PromptService>& promptService,
    const std::shared_ptr<service::ICRUDService<model::CreatePromptDto>>& promptCrudService,
    const std::shared_ptr<restbed::Resource>& resource
    )
    : m_promptService(promptService)
    , m_crudService(promptCrudService)
    , m_resource(resource)
    , m_loggerPrefix("PromptController::")
{
    m_resource->set_paths(rest::paths::PROMPTS);

    m_resource->set_method_handler("POST", std::bind(&PromptController::onAddNewPrompt, this, std::placeholders::_1));
    m_resource->set_method_handler("GET", std::bind(&PromptController::onGet, this, std::placeholders::_1));
}

std::shared_ptr<restbed::Resource> PromptController::getResource()
{
    return m_resource;
}

void PromptController::onAddNewPrompt(const std::shared_ptr<restbed::Session>& session)
{
    std::shared_ptr<model::CreatePromptDto> promptDto;
    m_crudService->post(session, promptDto);

    m_promptService->addNewPrompt(promptDto);
}

void PromptController::onGet(const std::shared_ptr<restbed::Session>& session)
{
    const auto request = session->get_request();
    const auto hasPathParameters = !request->get_path_parameters().empty();

    if (hasPathParameters)
    {
        onGetPrompt(session);
    }
    else
    {
        onGetAllPrompts(session);
    }
}

void PromptController::onGetAllPrompts(const std::shared_ptr<restbed::Session>& session)
{
    auto jsonStringPrompts = m_promptService->getAllPrompts();

    m_crudService->get(session, jsonStringPrompts);
}

void PromptController::onGetPrompt(const std::shared_ptr<restbed::Session>& session)
{
    const auto pathParameters = session->get_request()->get_path_parameters("id");

    std::string id = pathParameters.at("id");
    auto prompt = m_promptService->getPrompt(id);

    m_crudService->get(session, prompt);
}
