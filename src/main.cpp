#include "CRUDService.h"
#include "MemoRepo.h"
#include "Prompt.h"
#include "PromptController.h"
#include "PromptMemoDataAccess.h"
#include "PromptService.h"
#include "ResourceWrapper.h"
#include "config.h"

#include <iostream>
#include <memory>

#include <restbed>

using namespace rest;

int main(const int, const char**)
{
    const auto service = std::make_shared<restbed::Service>();
    const auto settings = std::make_shared<restbed::Settings>();
    const auto promptMemoDao = std::make_shared<service::PromptMemoDataAccess>(
          std::make_shared<repository::MemoRepo<std::shared_ptr<model::Prompt>, std::string>>());
    const auto promptService = std::make_shared<service::PromptService>(promptMemoDao);
    const auto crudPromptService = std::make_shared<service::CRUDService<model::CreatePromptDto>>(service);
    const auto resource = std::make_shared<service::ResourceWrapper>();
    const auto promptController = std::make_shared<controller::PromptController>(
          promptService, crudPromptService, resource);

    settings->set_port(std::stoi(SERVER_PORT));
    settings->set_default_header("Connection", "close");

    service->publish(resource->getResource());

    std::cout << "Server started on port: " << SERVER_PORT << "\n Version: " << VERSION
              << "\n Commit: " << GIT_COMMIT_HASH << std::endl;

    service->start(settings);

    return EXIT_SUCCESS;
}
