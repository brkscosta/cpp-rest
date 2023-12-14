#pragma once
#include "PromptMemoDataAccess.h"
#include "PromptService.h"
#include <corvusoft/restbed/session.hpp>
#include <memory>

namespace restbed
{
class Service;
class Session;
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

/*
 * Rest PromptController
 * @param std::shared_ptr<service::PromptService>
 */
class PromptController
{
  public:
    PromptController(
      const std::shared_ptr<restbed::Service>& service,
      const std::shared_ptr<service::PromptService>& promptService
    );
    ~PromptController() = default;

    /*
     * Handle the get request
     * @param const std::shared_ptr<restbed::Session>&
     */
    void handleGet(const std::shared_ptr<restbed::Session>& session);

    /*
     * Handle the post request
     * @param const std::shared_ptr<restbed::Session>&
     */
    void handlePost(const std::shared_ptr<restbed::Session>& session);

  private:
    std::shared_ptr<service::CRUDService<model::Prompt>> m_promptCRUDService;
    std::shared_ptr<service::PromptService> m_promptService;
};

};  // namespace rest::controller
